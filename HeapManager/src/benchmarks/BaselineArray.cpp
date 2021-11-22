#include "BaselineArray.h"
#include <iostream>

namespace benchmark {

	BaselineArray::BaselineArray(const Meta& meta) :
		m_intra_iters(meta.intra_benchmark_iterations) ,
		p_point_array(nullptr)
	{
		m_name = "BaselineArray";
	}

	void BaselineArray::BenchmarkImpl() {
		p_point_array = new Point[m_intra_iters];
		delete[] p_point_array;
	}

}