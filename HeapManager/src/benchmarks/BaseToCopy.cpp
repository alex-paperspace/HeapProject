#include "BaseToCopy.h"
//#include "../strats/files_here.h"

namespace benchmark {

	BaseToCopy::BaseToCopy(const Meta & meta) //:
		//initialize iteration # from meta.intra_benchmark_iterations
	{
		m_name = "BaseToCopy";
	}

	void BaseToCopy::BenchmarkImpl()
	{
		//some heap benchmark
	}

}