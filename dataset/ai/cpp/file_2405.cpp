#include <iostream>
int main() {
  for (int row = 1; row <= 3; ++row) {
    for (int column = 1; column <= row; ++column) {
      std::cout << '*' << ' ';
    }
    std::cout << '\n';
  }
}
