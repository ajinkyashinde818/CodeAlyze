#include <iostream>
void increment(int& number) {
    ++number;
}
int main() {
    int value = 89;
    increment(value);
    std::cout << value << '\n';
}
