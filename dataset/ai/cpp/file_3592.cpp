#include <iostream>
int main() {
	int data[] = { 36, 23, 9 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
