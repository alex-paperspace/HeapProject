#include "Improved_OneT.h"
#include "../strats/fixedpool.h"

namespace benchmark {

	Improved_OneT::Improved_OneT(const int& iterations) :
		m_pgeneric_vector_size(iterations) ,
		m_pgeneric_vector(iterations) 
	{
		m_name = "Improved_OneT";
	}

	void Improved_OneT::BenchmarkImpl() {

		pool::FixedPool<Point> mempool(m_pgeneric_vector_size); 

		for (int i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new (mempool.allocate()) Point();
		}
	}

}
