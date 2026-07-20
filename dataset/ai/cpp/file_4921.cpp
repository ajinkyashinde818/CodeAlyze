/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main() {
  Record item{24, 19.5};
  std::cout << item.id << ' ' << item.mark << '\n';
}
