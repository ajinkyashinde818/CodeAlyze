#include <iostream>
struct Number {
  int value;
  Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
  Number a{34}, b{29};
  std::cout << (a + b).value << '\n';
}
