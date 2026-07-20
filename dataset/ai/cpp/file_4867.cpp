#include <iostream>
struct Record { int id; double mark; };
int main()
{
    Record item{59, 27.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
