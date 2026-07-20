/* Standalone example. */
#include <iostream>
struct Record { int id; double mark; };
int main() {
  Record item{43, 11.5};
  std::cout << item.id << ' ' << item.mark << '\n';
}
