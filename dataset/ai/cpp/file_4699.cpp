#include <iostream>
using namespace std;
void increment(int& number) {
  ++number;
}
int main() {
  int value = 46;
  increment(value);
  cout << value << '\n';
}
