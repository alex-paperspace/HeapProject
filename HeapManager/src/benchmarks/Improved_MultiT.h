#pragma once

#include "Benchmark.h"
#include "../data/datatypes.h"
#include "../meta.h"
#include <vector>

namespace benchmark {

	typedef int type_1;
	typedef double type_2;

	//this can be refactored into a variadic template class if warranted

	class Improved_MultiT : public Benchmark {
	private:
		int m_total_iterations;
		int m_pvector1_size;
		int m_pvector2_size;
		std::vector<type_1 *> m_pvector1;
		std::vector<type_2 *> m_pvector2;
	protected:
		void BenchmarkImpl() override;
	public:
		explicit Improved_MultiT(const int& iterations);
	};

}

