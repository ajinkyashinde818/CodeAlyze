#include <iostream>
struct Number {
	int value;
	Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
	Number a{8}, b{30};
	std::cout << (a + b).value << '\n';
}
