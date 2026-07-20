#include <iostream>
int main() {
	int data[] = { 47, 30, 4 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
