#include "Baseline.h"
#include <iostream>

namespace benchmark {

	Baseline::Baseline() :
		m_pgeneric_vector_size(gc_benchmark_iterations) ,
		m_pgeneric_vector(gc_benchmark_iterations)
	{
		m_name = "Baseline";
		m_ready = true;
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