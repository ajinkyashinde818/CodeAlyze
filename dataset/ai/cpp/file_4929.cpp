#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{32, 27.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
