#include <iostream>
struct Record { int id; double mark; };
int main()
{
    Record item{19, 18.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
