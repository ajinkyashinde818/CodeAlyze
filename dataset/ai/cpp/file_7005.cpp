#include <iostream>
using namespace std;
struct Number {
  int value;
  Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
  Number a{83}, b{16};
  cout << (a + b).value << '\n';
}
