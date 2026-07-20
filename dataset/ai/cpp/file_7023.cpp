#include <iostream>
struct Number {
    int value;
    Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
    Number a{12}, b{3};
    std::cout << (a + b).value << '\n';
}
