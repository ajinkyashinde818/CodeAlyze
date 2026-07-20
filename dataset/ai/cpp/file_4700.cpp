#include <iostream>
void increment(int& number) {
  ++number;
}
int main() {
  int value = 47;
  increment(value);
  std::cout << value << '\n';
}
