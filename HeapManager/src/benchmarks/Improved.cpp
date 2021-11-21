#include "Improved.h"
#include "../memorypool.h"
#include <iostream>


namespace benchmark {

	Improved::Improved(const Meta& meta) :
		m_pgeneric_vector_size(meta.intra_benchmark_iterations) ,
		m_pgeneric_vector(meta.intra_benchmark_iterations) 
	{
		m_name = "Improved";
	}

	void Improved::BenchmarkImpl() {

		pool::PoolList<Point> mempool(m_pgeneric_vector_size); 

		for (int i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new (mempool.allocate()) Point();
		}
	}

}
