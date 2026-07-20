#include <iostream>
int main() {
	int data[] = { 88, 25, 4 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
