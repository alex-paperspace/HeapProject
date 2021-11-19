#include "BenchmarkManager.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include "printutil.h"

BenchmarkManager::BenchmarkManager() {

}

BenchmarkManager::~BenchmarkManager() {

}

void BenchmarkManager::pushBenchmark(const SharedBenchmark& benchmark) {
	m_benchmarksToRun.push(benchmark);
}

void BenchmarkManager::runBenchmarks(int numEach) {
	while (!m_benchmarksToRun.empty()) {
		SharedBenchmark currentBenchmark = m_benchmarksToRun.front();
		m_benchmarksToRun.pop();
		if (!currentBenchmark->isReady()) {
			assert(!"Unready benchmark should not be pushed to queue.");
			break;
		}
		double average = 0;
		for (int i = 1; i <= numEach; ++i) {
			double benchmarkTime = currentBenchmark->runBenchmark().count();
			average += benchmarkTime;
			std::cout << std::setw(15) << currentBenchmark->getName() \
				<< std::setw(15) << i \
				<< std::setw(15) << std::fixed << std::setprecision(6) << benchmarkTime \
				<< std::endl;
		}
		average /= numEach;
		m_averages[currentBenchmark->getName()] = average;
	}
	printutil::printBreak();
	std::cout << "All benchmarks finished." << std::endl;
	printutil::printBreak();
}

void BenchmarkManager::printAverages() {
	printutil::printAverageHeader();
	for (auto const& x : m_averages) {
		std::cout << std::setw(15) << std::fixed << std::setprecision(6) << x.first \
			<< std::setw(15) << std::fixed << std::setprecision(6) << x.second \
			<< std::endl;
	}
}
