#include "Improved.h"
#include "../memorypool.h"
#include <iostream>

namespace benchmark {



	Improved::Improved() :
		m_pgeneric_vector_size(gc_benchmark_iterations) ,
		m_pgeneric_vector(gc_benchmark_iterations) 
	{
		m_name = "Improved";
		m_ready = true;
	}

	void Improved::BenchmarkImpl() {

		using namespace pool;

		

		//std::vector<MemoryPool<Point>*> memPools;
		//MemoryPool<Point>* init_mem_pool = new MemoryPool<Point>();
		//memPools.push_back(init_mem_pool);

		//int mempoolsize = 4096;
		//
		//try {
		//	init_mem_pool->setPoolSize(mempoolsize);
		//}
		//catch (const std::invalid_argument& e) {
		//	delete init_mem_pool;
		//	std::cerr << "Invalid arg: " << e.what() << "\nExiting..." << std::endl;
		//	exit(EXIT_FAILURE);
		//}
		//
		//MemoryPool<Point>* currentPool = init_mem_pool;

		//for (size_t i = 0; i < m_pgeneric_vector_size; ++i) {
		//	Point* current = currentPool->allocate();
		//	if (current == nullptr) {
		//		//std::cout << "Current Pool full. Creating new Pool..." << std::endl;
		//		currentPool = new MemoryPool<Point>();
		//		currentPool->setPoolSize(mempoolsize);
		//		current = currentPool->allocate();
		//		memPools.push_back(currentPool);
		//	}
		//	m_pgeneric_vector[i] = new (current) Point(double(i), (double)i);
		//}

		//for (auto i = memPools.begin(); i != memPools.end(); ++i) {
		//	delete *i;
		//}
	}

}
