/* Standalone example. */
#include <iostream>
struct Number {
    int value;
    Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
    Number a{17}, b{8};
    std::cout << (a + b).value << '\n';
}
