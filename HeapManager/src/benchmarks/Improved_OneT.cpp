#include "Improved_OneT.h"
#include "../strats/fixedpool.h"
#include "../strats/pool_onet.h"

namespace benchmark {

	Improved_OneT::Improved_OneT(const int& iterations) :
		m_pvector(iterations) 
	{
		m_name = "Improved_OneT";
	}

	void Improved_OneT::BenchmarkImpl() {

#define USE_NONVARIADIC
#ifdef USE_NONVARIADIC
		pool::Pool_OneT<Point> mempool(m_pvector.size());
#else
		pool::FixedPool<Point> mempool(m_pvector.size());
#endif

		for (int i = 0; i < m_pvector.size(); ++i) {
			m_pvector[i] = new (mempool.allocate()) Point();
		}
	}

}
