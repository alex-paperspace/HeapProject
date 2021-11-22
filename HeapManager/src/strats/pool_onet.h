#pragma once

namespace pool {
	
	/*
	FixedPool is exactly this class, but with the additional ability to allocate several types.
	However, there seems to be a noticeable performance penalty when using FixedPool with just one type.
	Therefore, use Pool_OneT if you need to just use one type.
	*/

	template<class T>
	union _Node {
		T data;
		_Node* next;
		_Node() { next = nullptr; }
	};

	template<class T>
	class Pool_OneT {
		_Node<T>* const _head;
		_Node<T>* head;
	public:
		Pool_OneT(int count) :
			_head((_Node<T>*)calloc(count, sizeof(_Node<T>))) ,
			head(_head)
		{
			_Node<T>* cur = head;
			for (int i = 1; i < count; ++i) {
				cur->next = new (cur + 1) _Node<T>();
				cur = cur->next;
			}
		}

		~Pool_OneT() {
			free(_head);
		}

		_Node<T>* allocate() {
			if (head == nullptr) {
				return nullptr;
			}
			_Node<T>* ret = head;
			head = head->next;
			return ret;
		}

		void deallocate(T*& ptr) {
			_Node<T>* cur = reinterpret_cast<_Node<T>*>(ptr);
			ptr = nullptr;
			cur->next = head;
			head = cur;
		}
	};

}

