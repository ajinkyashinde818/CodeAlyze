#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{47, 11.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
