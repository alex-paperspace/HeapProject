#pragma once

#include "Benchmark.h"
#include "../data/datatypes.h"
#include "../meta.h"

namespace benchmark {

	class BaselineArray : public Benchmark {
	private:
		int m_intra_iters;
		Point* p_point_array;
	protected:
		void BenchmarkImpl() override;
	public:
		explicit BaselineArray(const int& iterations);
	};

}

#pragma once
