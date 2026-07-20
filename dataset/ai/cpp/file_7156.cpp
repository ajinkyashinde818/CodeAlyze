#include <iostream>
int area(int side) { return side * side; }
double area(double radius) { return 3.14 * radius * radius; }
int main() {
    std::cout << area(23) << '\n';
}
