#pragma once

#include <cassert>

namespace pool {
	
	template<class T>
	union Node {
		T data;
		Node* next;
		Node() { next = nullptr; }
		Node& operator=(const T& t) { 
			data = t;
			return *this;
		}
	};

	template<class T>
	class PoolList {
		Node<T>* head;
	public:
		PoolList(int count) {
			if (count < 1) {
				assert(!"Specified Node count invalid.");
			}
			head = new Node<T>;
			Node<T>* cur = head;
			for (int i = 1; i < count; ++i) {
				cur->next = new Node<T>;
				cur = cur->next;
			}
		}

		~PoolList() {
			Node<T>* cur = head;
			while (cur != nullptr) {
				head = head->next;
				delete cur;
				cur = head;
			}
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
			*ret = T();
			return ret;
		}

		void deallocate(T* ptr) {
			Node<T>* cur = reinterpret_cast<Node<T>*>(ptr);
			cur->next = head;
			head = cur;
		}
	};

}

