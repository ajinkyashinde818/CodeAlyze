#include <iostream>
int main() {
  int data[] = { 36, 11, 3 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
