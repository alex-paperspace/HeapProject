#pragma once

#include <variant>

namespace pool {

	/*
	this is pretty cool because variadic templates and std::variants allow us
	to use as many data types as we want.
	Note that this is still a Fixed Size Pool that allocates memory based on the
	largest template type.
	*/

	template<class... Types>
	union Node {
		std::variant<Types...> data; //does add a bit of padding when in use
		Node* next;
		Node() { next = nullptr; }
	};

	template<class... Types>
	class FixedPool {
		Node<Types...>* const _head;
		Node<Types...>* head;
	public:
		FixedPool(int count) :
			_head((Node<Types...>*)calloc(count, sizeof(Node<Types...>))),
			head(_head)
		{
			Node<Types...>* cur = head;
			for (int i = 1; i < count; ++i) {
				cur->next = new (cur + 1) Node<Types...>();
				cur = cur->next;
			}
		}

		~FixedPool() {
			free(_head);
		}

		Node<Types...>* allocate() {
			if (head == nullptr) {
				return nullptr;
			}
			Node<Types...>* ret = head;
			head = head->next;
			return ret;
		}

		template<typename T>
		void deallocate(T*& ptr) {
			Node<Types...>* cur = reinterpret_cast<Node<Types...>*>(ptr);
			ptr = nullptr;
			cur->next = head;
			head = cur;
		}
	};

}