#pragma once

#include "Benchmark.h"
#include "../data/datatypes.h"
#include "../meta.h"

namespace benchmark {

	class BaseToCopy : public Benchmark {
	private:
		//members
	protected:
		void BenchmarkImpl() override;
	public:
		explicit BaseToCopy(const int& iterations);
	};

}
