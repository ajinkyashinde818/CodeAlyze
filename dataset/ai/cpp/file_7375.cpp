#include <iostream>
using namespace std;
template <class T> T maximum(T left, T right) { return left > right ? left : right; }
int main() {
  cout << maximum(73, 6) << '\n';
}
