#include "BaseVariable.h"
#include "../strats/variablepool.h"

namespace benchmark {

	BaseVariable::BaseVariable(const Meta & meta) :
		m_pvector1_size(meta.intra_benchmark_iterations / 2) ,
		m_pvector2_size(meta.intra_benchmark_iterations / 2) ,
		m_pvector1(meta.intra_benchmark_iterations) ,
		m_pvector2(meta.intra_benchmark_iterations)
	{
		m_name = "benchmark";
	}

	void benchmark::BaseVariable::BenchmarkImpl()
	{

	}

}
