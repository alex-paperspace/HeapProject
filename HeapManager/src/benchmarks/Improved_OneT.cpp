#include "Improved_OneT.h"
#include "../strats/fixedpool.h"
#include "../strats/pool_onet.h"

namespace benchmark {

	Improved_OneT::Improved_OneT(const int& iterations) :
		m_pgeneric_vector_size(iterations) ,
		m_pgeneric_vector(iterations) 
	{
		m_name = "Improved_OneT";
	}

	void Improved_OneT::BenchmarkImpl() {

#define USE_ONETYPE
#ifdef USE_ONETYPE
		pool::Pool_OneT<Point> mempool(m_pgeneric_vector_size);
#else
		pool::FixedPool<Point> mempool(m_pgeneric_vector_size);
#endif

		for (int i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new (mempool.allocate()) Point();
		}
	}

}
