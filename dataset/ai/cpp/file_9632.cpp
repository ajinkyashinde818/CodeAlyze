/* Standalone example. */
#include <iostream>
int main() {
    int number = 52, divisor = 2;
    bool prime = number > 1;
    while (divisor * divisor <= number) {
        if (number % divisor == 0) prime = false;
        ++divisor;
    }
    std::cout << prime << '\n';
}
