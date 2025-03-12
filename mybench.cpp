#include "mybench.h"
#include <cmath>
#include <iostream>

void Benchmark::update_stats(double duration) {
  ++rounds;
  double delta = duration - mean;
  mean += delta / static_cast<double>(rounds);
  sum_sqdiff += delta * (duration - mean);
  std = std::sqrt(sum_sqdiff / static_cast<double>(rounds));
  if (rounds == 1) {
    min = duration;
    max = duration;
  } else {
    if (duration < min)
      min = duration;
    if (duration > max)
      max = duration;
  }
}

void Benchmark::print() const {
  std::cout << "round:\t" << rounds << "\nmean:\t" << mean << "\nstd:\t" << std
            << "\nmin:\t" << min << "\nmax:\t" << max << "\n\n";
}

void Benchmark::reset() {
  rounds = 0;
  mean = 0;
  std = 0;
  min = 0;
  max = 0;
  sum_sqdiff = 0;
}
