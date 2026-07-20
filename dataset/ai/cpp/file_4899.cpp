#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{91, 28.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
