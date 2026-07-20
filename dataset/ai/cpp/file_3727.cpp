#include <iostream>
int main() {
	int data[] = { 82, 3, 4 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
