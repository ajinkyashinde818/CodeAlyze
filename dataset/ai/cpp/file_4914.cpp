/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main() {
	Record item{17, 12.5};
	std::cout << item.id << ' ' << item.mark << '\n';
}
