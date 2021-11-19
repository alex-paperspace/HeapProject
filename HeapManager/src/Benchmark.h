#pragma once

#include <chrono>
#include <string>

namespace benchmark {

	const int gc_benchmark_iterations = 256;

	typedef std::chrono::duration<double> ChronoDuration;

	class Benchmark {
	protected:
		std::string m_name;
		bool m_ready;

		virtual void BenchmarkImpl() = 0;
	public:
		Benchmark();

		ChronoDuration runBenchmark();
		bool isReady() const { return m_ready; }
		std::string getName() const { return m_name; }
	};

}

