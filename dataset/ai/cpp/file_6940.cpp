#include <iostream>
using namespace std;
struct Number {
  int value;
  Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
  Number a{18}, b{13};
  cout << (a + b).value << '\n';
}
