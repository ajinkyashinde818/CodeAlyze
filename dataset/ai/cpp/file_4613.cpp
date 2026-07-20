/* Standalone example. */
#include <iostream>
void increment(int& number) {
	++number;
}
int main() {
	int value = 49;
	increment(value);
	std::cout << value << '\n';
}
