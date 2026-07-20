#include <iostream>
void increment(int& number) {
    ++number;
}
int main() {
    int value = 73;
    increment(value);
    std::cout << value << '\n';
}
