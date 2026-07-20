#include <iostream>
int main() {
	int data[] = { 53, 21, 4 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
