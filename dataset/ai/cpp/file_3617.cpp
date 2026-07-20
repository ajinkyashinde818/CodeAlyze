#include <iostream>
int main() {
	int data[] = { 61, 17, 6 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
