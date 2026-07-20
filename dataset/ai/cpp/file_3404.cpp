#include <iostream>
int main() {
  int data[] = { 26, 21, 3 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
