#include <iostream>
int main() {
  int data[] = { 57, 17, 4 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
