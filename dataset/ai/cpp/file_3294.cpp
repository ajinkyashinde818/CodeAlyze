#include <iostream>
int main() {
  int data[] = { 5, 4, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
