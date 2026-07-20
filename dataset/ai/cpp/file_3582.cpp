#include <iostream>
int main() {
	int data[] = { 26, 13, 6 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
