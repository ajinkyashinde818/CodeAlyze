#include <iostream>
struct Record { int id; double mark; };
int main() {
    Record item{6, 32.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
