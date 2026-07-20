#include <iostream>
struct Record { int id; double mark; };
int main() {
    Record item{56, 20.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
