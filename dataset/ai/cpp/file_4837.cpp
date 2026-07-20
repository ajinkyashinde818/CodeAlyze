/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main()
{
    Record item{29, 28.5};
    std::cout << item.id << ' ' << item.mark << '\n';
}
