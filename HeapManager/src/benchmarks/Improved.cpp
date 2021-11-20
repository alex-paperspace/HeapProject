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

		using namespace pool;

		PoolList<Point> pool(m_pgeneric_vector_size);

		for (int i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new (pool.allocate()) Point();
		}

		for (int i = 0; i < m_pgeneric_vector_size; ++i) {
			pool.deallocate(m_pgeneric_vector[i]);
		}

	}

}
