#include "Benchmark.h"

namespace benchmark {

	Benchmark::Benchmark() :
		m_ready(false)
	{
	}

	ChronoDuration Benchmark::runBenchmark() {
		auto start = std::chrono::steady_clock::now();
		BenchmarkImpl();
		auto end = std::chrono::steady_clock::now();
		ChronoDuration elapsed = end - start;
		return elapsed;
	}

}