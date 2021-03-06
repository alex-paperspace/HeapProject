#include "Improved_MultiT.h"
#include "../strats/fixedpool.h"

namespace benchmark {

	Improved_MultiT::Improved_MultiT(const int& iterations) :
		m_total_iterations((iterations > 1) ? iterations : 2 ), //for the very odd case of specifying 1 iteration (which doesn't make sense for this benchmark)
		m_pvector1(m_total_iterations / 2) ,
		m_pvector2(m_total_iterations / 2)
	{
		m_name = "Improved_MultiT";
	}

	void benchmark::Improved_MultiT::BenchmarkImpl()
	{
		pool::FixedPool<type_1, type_2> mempool(m_total_iterations);

		for (int i = 0; i < m_pvector1.size(); ++i) {
			m_pvector1[i] = new (mempool.allocate()) type_1;
		}

		/*
		for (int i = 0; i < m_pvector1_size; ++i) {
			mempool.deallocate(m_pvector1[i]);
		}
		*/

		/*
		If we uncomment above, we deallocate memory used by int vector ^ and allocate it for use by the double vector below.
		of course, the double vector will end up allocating new memory if
		(sizeof(int) * # of ints to allocate) < (sizeof(double) * # of doubles to allocate).
		This is why the initial mempool allocation allocates (m_total_iterations * sizeof(Node<Types...>).
		sizeof(Node<Types...>) is going to use the largest size of all the template types.
		*/

		for (int i = 0; i < m_pvector2.size(); ++i) {
			m_pvector2[i] = new (mempool.allocate()) type_2;
		}
	}

}
