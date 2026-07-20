#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{57, 21.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
