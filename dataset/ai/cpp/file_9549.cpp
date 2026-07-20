#include <iostream>
using namespace std;
int main() {
  int number = 58, divisor = 2;
  bool prime = number > 1;
  while (divisor * divisor <= number) {
    if (number % divisor == 0) prime = false;
    ++divisor;
  }
  cout << prime << '\n';
}
