#include <iostream>
int main() {
	int data[] = { 60, 20, 7 };
	int sum = 0;
	for (int item : data) sum += item;
	std::cout << sum << '\n';
}
