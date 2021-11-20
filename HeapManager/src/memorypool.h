#pragma once

#include <variant>
#include <list>

namespace pool {

	template<class T>
	class Chunk {
		std::variant<char*, T> w;
	};
	

	template<class T>
	class Pool {
		std::list<T> m_list;
	public:
		Pool(size_t count);
	};

	template<class T>
	inline Pool<T>::Pool(size_t count) :
		m_list(count)
	{

	}

}

