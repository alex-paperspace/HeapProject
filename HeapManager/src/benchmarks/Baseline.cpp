#include "Baseline.h"

namespace benchmark {

	Baseline::Baseline(const int& iterations) :
		m_pgeneric_vector_size(iterations) ,
		m_pgeneric_vector(iterations)
	{
		m_name = "Baseline";
	}

	void Baseline::BenchmarkImpl() {
		for (size_t i = 0; i < m_pgeneric_vector_size; ++i) {
			m_pgeneric_vector[i] = new Point((double)i, (double)i);
		}
		for (size_t i = 0; i < m_pgeneric_vector_size; ++i) {
			delete m_pgeneric_vector[i];
			m_pgeneric_vector[i] = nullptr;
		}
	}

}