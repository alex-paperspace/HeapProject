#pragma once

#include "Benchmark.h"
#include "../data/datatypes.h"
#include "../meta.h"
#include <vector>

namespace benchmark {

	class Improved_OneT : public Benchmark {
	private:
		std::vector<Point *> m_pvector;
	protected:
		void BenchmarkImpl() override;
	public:
		explicit Improved_OneT(const int& iterations);
	};

}

