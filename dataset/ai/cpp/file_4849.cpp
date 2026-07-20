#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{41, 9.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
