#pragma once

#include "../Benchmark.h"
#include "../data/datatypes.h"
#include <vector>

namespace benchmark {

	class Baseline : public Benchmark {
	private:
		size_t m_pgeneric_vector_size;
		std::vector<Point *> m_pgeneric_vector;
	protected:
		void BenchmarkImpl() override;
	public:
		Baseline();
	};

}