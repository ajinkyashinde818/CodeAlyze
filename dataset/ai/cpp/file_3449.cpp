#include <iostream>
int main() {
  int data[] = { 71, 4, 6 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
