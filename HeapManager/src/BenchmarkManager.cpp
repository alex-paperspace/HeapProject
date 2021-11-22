#include "BenchmarkManager.h"
#include <iostream>
#include <iomanip>
#include "printutil.h"
#include "data/datatypes.h"

BenchmarkManager::BenchmarkManager()
{

}

BenchmarkManager::~BenchmarkManager() {

}

void BenchmarkManager::pushBenchmark(const SharedBenchmark& benchmark) {
	m_benchmarksToRun.push(benchmark);
}

void BenchmarkManager::runBenchmarks(int numEach) {
	while (!m_benchmarksToRun.empty()) {
		printutil::printBreak();
		SharedBenchmark currentBenchmark = m_benchmarksToRun.front();
		m_benchmarksToRun.pop();
		double average = 0;
		for (int i = 1; i <= numEach; ++i) {
			double benchmarkTime = currentBenchmark->runBenchmark().count();
			average += benchmarkTime;
			std::cout << std::setw(15) << currentBenchmark->getName() \
				<< std::setw(15) << i \
				<< std::setw(15) << std::fixed << std::setprecision(6) << benchmarkTime * 1000 \
				<< std::endl;
		}
		average /= numEach;
		averageId temp = { currentBenchmark->getName() , average };
		m_averages.push_back(temp);
	}
	printutil::printBreak();
	std::cout << "All benchmarks finished." << std::endl;
	printutil::printBreak();
}

void BenchmarkManager::setup(Meta& meta) {
	std::cout << "Welcome to Heap Benchmarker.\nPlease specify how many items each benchmark should allocate:\n";

	{
		int intra, iters;
		std::cin >> intra;
		std::cout << "Please specify how many iterations to run on each Benchmark:\n";
		std::cin >> iters;
		if (intra < 1 || iters < 1) {
			throw std::invalid_argument("Invalid inputs.");
		}
		else {
			meta.intra_benchmark_iterations = intra;
			meta.benchmark_iterations = iters;
		}
	}
	
	printutil::printBreak();
	printutil::printColumns();
}

void BenchmarkManager::printAverages() {
	printutil::printAverageHeader();
	for (auto i = m_averages.begin(); i != m_averages.end(); ++i) {
		std::cout << std::setw(15) << std::fixed << std::setprecision(6) << (*i).name \
			<< std::setw(15) << std::fixed << std::setprecision(6) << (*i).average * 1000 \
			<< std::endl;
	}
}
