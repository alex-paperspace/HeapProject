#pragma once

#include <cassert>

namespace pool {
	
	template<class T>
	union Node {
		T data;
		Node* next;
		Node() { next = nullptr; }
	};

	template<class T>
	class PoolList {
		Node<T>* _head;
		Node<T>* head;
	public:
		PoolList(int count) :
			head(nullptr)
		{
			if (count < 1) {
				assert(!"Specified Node count invalid.");
			}
			_head = (Node<T>*)calloc(count, sizeof(Node<T>));
			head = _head;
			Node<T>* cur = head;
			for (int i = 1; i < count; ++i) {
				cur->next = new (cur + 1) Node<T>();
				cur = cur->next;
			}
		}

		~PoolList() {
			free(_head);
			/*Node<T>* cur = head;
			while (cur != nullptr) {
				head = head->next;
				std::cout << sizeof(*cur) << std::endl;
				delete cur;
				cur = head;
			}*/
		}

		Node<T>* front() const {
			return head;
		}

		Node<T>* allocate() {
			if (head == nullptr) {
				return nullptr;
			}
			Node<T>* ret = head;
			head = head->next;
			return ret;
		}

		void deallocate(T* ptr) {
			Node<T>* cur = reinterpret_cast<Node<T>*>(ptr);
			cur->next = head;
			head = cur;
		}
	};

}

