/* Standalone example. */
#include <iostream>
int main() {
	int data[] = { 18, 28, 8 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
