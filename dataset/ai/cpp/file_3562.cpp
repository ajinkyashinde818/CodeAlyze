#include <iostream>
int main() {
	int data[] = { 6, 24, 7 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
