#include <iostream>
int main() {
	int data[] = { 54, 29, 7 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
