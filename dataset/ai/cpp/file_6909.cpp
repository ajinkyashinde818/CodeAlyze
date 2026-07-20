/* Standalone example. */
#include <iostream>
struct Number {
	int value;
	Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
	Number a{76}, b{13};
	std::cout << (a + b).value << '\n';
}
