#include "BaseVariable.h"
#include "../strats/variablepool.h"

namespace benchmark {

	BaseVariable::BaseVariable(const int& iterations) :
		m_pvector1_size(iterations / 2) ,
		m_pvector2_size(iterations / 2) ,
		m_pvector1(iterations) ,
		m_pvector2(iterations)
	{
		m_name = "benchmark";
	}

	void benchmark::BaseVariable::BenchmarkImpl()
	{

	}

}
