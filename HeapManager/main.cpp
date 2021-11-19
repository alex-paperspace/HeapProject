#include <iostream>
#include <memory>
#include <iomanip>
#include "src/HeapManager.h"
#include "src/BenchmarkManager.h"
#include "src/benchmarks/Benchmarks.h"
#include "src/printutil.h"

BenchmarkManager & g_benchManager = BenchmarkManager::getInstance();

int main()
{
	std::cout << "Welcome to Heap Benchmarker.\n";
	printutil::printBreak();
	printutil::printColumns();

	SharedBenchmark b1 = std::make_shared<benchmark::Baseline>();
	SharedBenchmark b2 = std::make_shared<benchmark::Improved>();

	g_benchManager.pushBenchmark(b1);
	g_benchManager.pushBenchmark(b2);
	g_benchManager.runBenchmarks(3);

	g_benchManager.printAverages();
	printutil::printBreak();
	return 0;
}
