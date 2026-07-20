#include <iostream>
#include <stdexcept>
using namespace std;
int main() {
  try {
    if (4 % 2) throw runtime_error("odd");
    cout << "even\n";
  } catch (const exception& error) {
    cout << error.what() << '\n';
  }
}
