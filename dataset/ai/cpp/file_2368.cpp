#include <iostream>
int main() {
	for (int row = 1; row <= 8; ++row) {
		for (int column = 1; column <= row; ++column) {
			std::cout << '*' << ' ';
		}
		std::cout << '\n';
	}
}
