#include <iostream>
struct Record { int id; double mark; };
int main() {
  Record item{18, 17.5};
  std::cout << item.id << ' ' << item.mark << '\n';
}
