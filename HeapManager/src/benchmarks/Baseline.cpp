#include "Baseline.h"

namespace benchmark {

	Baseline::Baseline(const int& iterations) :
		m_pvector(iterations)
	{
		m_name = "Baseline";
	}

	void Baseline::BenchmarkImpl() {
		for (size_t i = 0; i < m_pvector.size(); ++i) {
			m_pvector[i] = new Point((double)i, (double)i);
		}
		for (size_t i = 0; i < m_pvector.size(); ++i) {
			delete m_pvector[i];
		}
	}

}