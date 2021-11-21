#pragma once

#include <chrono>
#include <string>

namespace benchmark {

	typedef std::chrono::duration<double> ChronoDuration;

	class Benchmark {
	protected:
		std::string m_name;
		virtual void BenchmarkImpl() = 0;
	public:
		ChronoDuration runBenchmark();
		std::string getName() const { return m_name; }
	};

}

