#include <iostream>
int main() {
  int data[] = { 18, 5, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
