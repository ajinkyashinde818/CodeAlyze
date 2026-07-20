#include <iostream>
int main() {
  int data[] = { 11, 17, 6 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
