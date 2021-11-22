#include <iostream>
#include <memory>
#include "src/BenchmarkManager.h"
#include "src/benchmarks/benchmarktypes.h"
#include "src/meta.h"
#include "src/printutil.h"

BenchmarkManager & g_benchManager = BenchmarkManager::getInstance();

int main()
{
	Meta meta;

	try {
		g_benchManager.setup(meta);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	}

	SharedBenchmark b1 = std::make_shared<benchmark::Baseline>(meta.intra_benchmark_iterations);
	SharedBenchmark b2 = std::make_shared<benchmark::BaselineArray>(meta.intra_benchmark_iterations);
	SharedBenchmark b3 = std::make_shared<benchmark::Improved_OneT>(meta.intra_benchmark_iterations);
	SharedBenchmark b4 = std::make_shared<benchmark::Improved_MultiT>(meta.intra_benchmark_iterations);

	g_benchManager.pushBenchmark(b1);
	g_benchManager.pushBenchmark(b2);
	g_benchManager.pushBenchmark(b3);
	g_benchManager.pushBenchmark(b4);

	g_benchManager.runBenchmarks(meta.benchmark_iterations);

	g_benchManager.printAverages();
	printutil::printBreak();
	return 0;
}
