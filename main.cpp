#include "mybench.h"
#include <cmath>

bool compete1(const int player1_power, const int player2_power) {
	double player1_chance = 1 / (1 + pow(10, (player2_power - player1_power) / 400));
	double player2_chance = 1 / (1 + pow(10, (player1_power - player2_power) / 400));
    return (player1_chance>player2_chance)? true: false;
}

bool compete2(const int player1_power, const int player2_power) {
	double player1_chance = 1 / (1 + pow(10, (player2_power - player1_power) / 400));
	double player2_chance = 1- player1_chance;
    return (player1_chance>player2_chance)? true: false;
}


void f1() { 
  volatile double res = compete1(1000, 1200);
 }

void f2() { 
  volatile double res = compete2(1000, 1200);
 }

int main() {
  Benchmark b;
  b.run(f1, 100, 1000000000);
  b.run(f1, 100, 1000000000);
  b.run(f2, 100, 1000000000);
  return 0;
}
