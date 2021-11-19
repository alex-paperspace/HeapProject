#pragma once

#include <map>

namespace pool {

	template<class T>
	class MemoryPool {
	private:
		char* m_buffer;
		size_t m_itemSize;
		std::map<void*, bool> m_used;
	public:

		
		explicit MemoryPool(size_t poolsize) :
			m_itemSize(sizeof(T))
		{
			if (poolsize < 2) {
				throw std::invalid_argument("Specified memory pool size too low.");
			}
			poolsize = poolsize - (poolsize % 2);
		}

		~MemoryPool() {
			delete[] m_buffer;
		}

		T* allocate(size_t size) {
			for (auto it = m_used.begin(); it != m_used.end(); ++it) {
				//if (it->second)
			}

			T* retptr;
			return retptr;
		}

		void deallocate(T*& dptr) {


		}

	private:
		MemoryPool(const MemoryPool&) = delete;
		MemoryPool& operator=(const MemoryPool&) = delete;
	};

}

