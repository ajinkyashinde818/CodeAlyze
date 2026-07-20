#include <iostream>
using namespace std;
void increment(int& number) {
  ++number;
}
int main() {
  int value = 66;
  increment(value);
  cout << value << '\n';
}
