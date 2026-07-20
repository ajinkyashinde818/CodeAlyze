#include <iostream>
struct Record { int id; double mark; };
int main() {
    Record item{46, 10.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
