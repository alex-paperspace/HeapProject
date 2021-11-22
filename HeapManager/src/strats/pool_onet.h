#pragma once

namespace pool {
	

	//obsolete now that FixedPool exists, which can act as a Pool_OneT anyway.

	//template<class T>
	//union Node {
	//	T data;
	//	Node* next;
	//	Node() { next = nullptr; }
	//};

	///*PoolList, a SinglyLL solution for allocating memory to fixed size objects from a block.
	//No management is necessary. Once PoolList is destructed, all memory is freed.*/

	//template<class T>
	//class Pool_OneT {
	//	Node<T>* const _head;
	//	Node<T>* head;
	//public:
	//	Pool_OneT(int count) :
	//		_head((Node<T>*)calloc(count, sizeof(Node<T>))) ,
	//		head(_head)
	//	{
	//		Node<T>* cur = head;
	//		for (int i = 1; i < count; ++i) {
	//			cur->next = new (cur + 1) Node<T>();
	//			cur = cur->next;
	//		}
	//	}

	//	~Pool_OneT() {
	//		free(_head);
	//	}

	//	Node<T>* allocate() {
	//		if (head == nullptr) {
	//			return nullptr;
	//		}
	//		Node<T>* ret = head;
	//		head = head->next;
	//		return ret;
	//	}

	//	void deallocate(T*& ptr) {
	//		Node<T>* cur = reinterpret_cast<Node<T>*>(ptr);
	//		ptr = nullptr;
	//		cur->next = head;
	//		head = cur;
	//	}
	//};

}

