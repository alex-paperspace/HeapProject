#include "Improved.h"
#include "../strats/fixedpool.h"

namespace benchmark {

	Improved::Improved(const int& iterations) :
		m_pgeneric_vector_size(iterations) ,
		m_pgeneric_vector(iterations) 
	{
		m_name = "Improved";
	}

	void Improved::BenchmarkImpl() {

		pool::FixedPool<Point> mempool(m_pgeneric_vector_size); 

		for (int i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new (mempool.allocate()) Point();
		}
	}

}
