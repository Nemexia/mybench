#pragma once

#include <chrono>

class Benchmark {
private:
  long long rounds{0};
  double mean{0.0};
  double std{0.0};
  double min{0.0};
  double max{0.0};
  double sum_sqdiff{0.0};

  void update_stats(double duration);
  void print() const;

public:
  template <typename Func>
  void run(Func func, int rounds_todo = 100, int cycles_todo = 1) {
    for (int r{0}; r < rounds_todo; ++r) {
      auto start = std::chrono::high_resolution_clock::now();
      for (int c{0}; c < cycles_todo; ++c) {
        func();
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto duration =
          std::chrono::duration_cast<std::chrono::microseconds>(end - start)
              .count();
      update_stats(static_cast<double>(duration) / cycles_todo);
    }
    print();
  }
};
