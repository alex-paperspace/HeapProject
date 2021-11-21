#include <iostream>
#include <memory>
#include <iomanip>
#include "src/BenchmarkManager.h"
#include "src/benchmarks/benchmarktypes.h"
#include "src/printutil.h"

BenchmarkManager & g_benchManager = BenchmarkManager::getInstance();

int main()
{
	try {
		g_benchManager.setup();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}

	SharedBenchmark b1 = std::make_shared<benchmark::Baseline>(g_benchManager.m_meta);
	SharedBenchmark b2 = std::make_shared<benchmark::Improved>(g_benchManager.m_meta);

	g_benchManager.pushBenchmark(b1);
	g_benchManager.pushBenchmark(b2);
	g_benchManager.runBenchmarks(g_benchManager.m_meta.benchmark_iterations);

	g_benchManager.printAverages();
	printutil::printBreak();
	return 0;
}
