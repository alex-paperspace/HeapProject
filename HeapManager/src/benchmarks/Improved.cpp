#include "Improved.h"
#include "../memorypool.h"
#include <iostream>

namespace benchmark {

	Improved::Improved() :
		m_pgeneric_vector_size(gc_benchmark_iterations) ,
		m_pgeneric_vector(gc_benchmark_iterations) 
	{
		m_name = "Improved";
		m_ready = true;
	}

	void Improved::BenchmarkImpl() {
		try {
			pool::MemoryPool<Point> somepool(1);
		}
		catch (const std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			exit(EXIT_FAILURE);
		}
		
		for (size_t i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new Point((double)i, (double)i);
		}
		for (size_t i = 0; i < m_pgeneric_vector_size; ++i) {
			delete m_pgeneric_vector[i];
			m_pgeneric_vector[i] = nullptr;
		}
	}

}
