#include <iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void sort(int &a, int &b, int &c) {
  if (b < c) swap(b, c);
  if (a < b) swap(a, b);
  if (b < c) swap(b, c);
}

int count(int b, int n) {
  return (n % b == 0) ? 1 : 0;
}

int count(int g, int b, int n) {
  int sum = 0;
  while (n >= 0) {
    sum += count(b, n);
    n -= g;
  }
  return sum;
}

int count(int r, int g, int b, int n) {
  int sum = 0;
  while (n >= 0) {
    sum += count(g, b, n);
    n -= r;
  }
  return sum;
}

int main(void) {
  int r, g, b, n;
  std::cin >> r >> g >> b >> n;
  sort(r, g, b);
  std::cout << count(r, g, b, n);
  return 0;
}
