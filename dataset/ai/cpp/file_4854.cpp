#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{46, 14.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
