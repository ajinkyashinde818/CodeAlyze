#include <iostream>
using namespace std;
struct Number {
  int value;
  Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
  Number a{12}, b{11};
  cout << (a + b).value << '\n';
}
