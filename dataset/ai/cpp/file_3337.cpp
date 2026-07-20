#include <iostream>
int main() {
	int data[] = { 48, 16, 6 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
