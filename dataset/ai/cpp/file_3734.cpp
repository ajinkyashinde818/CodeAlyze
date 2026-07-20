#include <iostream>
int main() {
  int data[] = { 89, 10, 4 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
