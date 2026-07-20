/* Standalone example. */
#include <iostream>
int main() {
	int data[] = { 53, 32, 8 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
