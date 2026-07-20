/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main() {
    Record item{50, 18.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
