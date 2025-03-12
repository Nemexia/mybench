#include "mybench.h"
#include <iostream>

void f1() {
  constexpr int size{1000};
  constexpr int cycle{100};
  volatile int data[size];
  for (auto &d : data)
    d = 0;

  data[0] = 1;
  for (int c{0}; c < cycle; ++c)
    for (int i{0}; i < size; ++i)
      data[i] = data[i - 1] + 1;

  //  std::cout << data[0] << '.';
}

int main() {
  Benchmark b;
  b.run(f1, 25, 1000);
  b.run(f1, 25, 1000);
  return 0;
}
