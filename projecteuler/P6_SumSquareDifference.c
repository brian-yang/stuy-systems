#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("%d\n", squareSum(100) - sumOfSquares(100));
}

// Squares the sum of all numbers from 1 to n
int squareSum(int n) {
  return (n * n * (n+1) * (n+1)) / 4;
}

// Sums the squares of all numbers from 1 to n
int sumOfSquares(int n) {
  return (n * (n + 1) * ((2 * n) + 1)) / 6;
}
