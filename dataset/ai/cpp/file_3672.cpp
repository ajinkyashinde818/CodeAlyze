#include <iostream>
int main() {
	int data[] = { 27, 10, 5 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
