#include <iostream>
using namespace std;
int area(int side) { return side * side; }
double area(double radius) { return 3.14 * radius * radius; }
int main() {
  cout << area(39) << '\n';
}
