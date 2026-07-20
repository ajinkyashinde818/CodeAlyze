/* Standalone example. */
#include <iostream>
int main() {
  int data[] = { 12, 3, 8 };
  int sum = 0;
  for (int item : data) sum += item;
  std::cout << sum << '\n';
}
