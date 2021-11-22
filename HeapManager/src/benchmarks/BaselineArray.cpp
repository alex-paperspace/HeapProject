#include "BaselineArray.h"

namespace benchmark {

	BaselineArray::BaselineArray(const int& iterations) :
		m_intra_iters(iterations) ,
		p_point_array(nullptr)
	{
		m_name = "BaselineArray";
	}

	void BaselineArray::BenchmarkImpl() {
		p_point_array = new Point[m_intra_iters];
		delete[] p_point_array;
	}

}