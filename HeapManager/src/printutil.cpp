#include "printutil.h"
#include <iostream>
#include <iomanip>

namespace printutil {

	void printColumns() {
		std::cout << std::setw(15) << "Benchmark-Name" \
			<< std::setw(15) << "Iteration" \
			<< std::setw(15) << "Time(s)" \
			<< std::endl;
	}

	void printBreak() {
		for (int i = 0; i < 45; ++i) {
			std::cout << '-';
		}
		std::cout << std::endl;
	}

	void printAverageHeader() {
		std::cout << std::setw(15) << "Benchmark-Name" \
			<< std::setw(15) << "Avg Time(s)" \
			<< std::endl;
	}
}
 