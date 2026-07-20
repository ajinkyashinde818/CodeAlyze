#include <iostream>
template <class T> T maximum(T left, T right) { return left > right ? left : right; }
int main() {
  std::cout << maximum(44, 8) << '\n';
}
