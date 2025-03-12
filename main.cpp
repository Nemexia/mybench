#include "mybench.h"
#include <thread>

void f1() {
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

int main() {
	Benchmark b;
	b.run(f1, 100, 100);
	b.print();
	return 0;
}
