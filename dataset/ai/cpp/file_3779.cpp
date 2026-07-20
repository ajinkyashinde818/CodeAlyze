#include <iostream>
int main() {
  int data[] = { 45, 24, 7 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
