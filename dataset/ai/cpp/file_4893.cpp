/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main() {
    Record item{85, 22.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
