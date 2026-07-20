#include <iostream>
int main() {
	int data[] = { 70, 30, 3 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
