#pragma once

#include <queue>
#include <map>
#include "benchmarks/Benchmark.h"
#include "meta.h"

typedef std::shared_ptr<benchmark::Benchmark> SharedBenchmark;

class BenchmarkManager
{
private:
	BenchmarkManager();
	~BenchmarkManager();
	BenchmarkManager(BenchmarkManager const&) = delete;
	void operator=(BenchmarkManager const&) = delete;

	std::queue<SharedBenchmark> m_benchmarksToRun;
	std::map < std::string, double > m_averages;

public:

	static BenchmarkManager& getInstance() {
		static BenchmarkManager instance;
		return instance;
	}

	void pushBenchmark(const SharedBenchmark& benchmark);
	void runBenchmarks(int numEach = 1);

	void setup(Meta& meta);
	void printAverages();	
};

