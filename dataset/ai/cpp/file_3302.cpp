#include <iostream>
int main() {
	int data[] = { 13, 12, 6 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
