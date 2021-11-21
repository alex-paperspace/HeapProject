#pragma once

#include "Benchmark.h"
#include "../data/datatypes.h"
#include "../meta.h"
#include <vector>

namespace benchmark {

	class Improved : public Benchmark {
	private:
		int m_pgeneric_vector_size;
		std::vector<Point *> m_pgeneric_vector;
	protected:
		void BenchmarkImpl() override;
	public:
		explicit Improved(const Meta& meta);
	};

}

