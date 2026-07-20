/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main() {
  Record item{8, 7.5};
  std::cout << item.id << ' ' << item.mark << '\n';
}
