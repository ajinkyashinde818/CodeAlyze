#include <iostream>
template <class T> T maximum(T left, T right) { return left > right ? left : right; }
int main() {
  std::cout << maximum(13, 12) << '\n';
}
