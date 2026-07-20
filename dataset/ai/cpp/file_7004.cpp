#include <iostream>
struct Number {
	int value;
	Number operator+(Number other) const { return {value + other.value}; }
};
int main() {
	Number a{82}, b{15};
	std::cout << (a + b).value << '\n';
}
