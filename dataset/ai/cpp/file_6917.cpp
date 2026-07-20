#include <iostream>
struct Number {
    int value;
    Number operator+(Number other) const { return {value + other.value}; }
};
int main()
{
    Number a{84}, b{21};
    std::cout << (a + b).value << '\n';
}
