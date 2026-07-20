/* Standalone example. */
#include <iostream>
struct Number {
	int value;
	Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
	Number a{41}, b{9};
	std::cout << (a + b).value << '\n';
}
