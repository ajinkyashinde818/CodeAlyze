/* Standalone example. */
#include <iostream>
void increment(int& number) {
  ++number;
}
int main() {
  int value = 24;
  increment(value);
  std::cout << value << '\n';
}
