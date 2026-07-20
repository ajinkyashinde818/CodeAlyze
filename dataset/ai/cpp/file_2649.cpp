#include <iostream>
using namespace std;
int main() {
  for (int row = 1; row <= 9; ++row) {
    for (int column = 1; column <= row; ++column) {
      cout << '*' << ' ';
    }
    cout << '\n';
  }
}
