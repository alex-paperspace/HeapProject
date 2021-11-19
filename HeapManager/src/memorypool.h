#pragma once

#include <map>

namespace pool {

	template<class T>
	class MemoryPool {
	private:
		char* m_buffer;
		unsigned int m_itemSize;
		unsigned int m_items;
		std::map<T*, bool> m_used;
	public:

		MemoryPool() :
			m_itemSize(sizeof(T))
		{

		}
		
		void setPoolSize(unsigned int poolsize) 
		{
			if (poolsize < 2) {
				throw std::invalid_argument("Specified memory pool size too low for type size.");
			}
			poolsize = poolsize - (poolsize % m_itemSize);
			m_items = poolsize / m_itemSize;
			m_buffer = new char[poolsize];
			T* j = reinterpret_cast<T*>(m_buffer);
			for (unsigned int i = 0; i < m_items; ++i) {
				m_used[j] = false;
				j++;
			}
			//std::cout << "Memory pool created with poolsize: " << poolsize << std::endl;
		} 

		~MemoryPool() {
			delete[] m_buffer;
		}

		T* allocate() {
			for (auto it = m_used.begin(); it != m_used.end(); ++it) {
				if (it->second == false) {
					it->second = true;
					return it->first;
				}
			}
			return nullptr;
		}

		void deallocate(T*& dptr) {
			m_used[dptr] = false;
			dptr = nullptr;
		}

	private:
		MemoryPool(const MemoryPool&) = delete;
		MemoryPool& operator=(const MemoryPool&) = delete;
	};

}

