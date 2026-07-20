#include <iostream>
void increment(int& number) {
	++number;
}
int main() {
	int value = 80;
	increment(value);
	std::cout << value << '\n';
}
