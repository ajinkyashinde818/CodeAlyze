#include <iostream>
using namespace std;
struct Record { int id; double mark; };
int main() {
  Record item{18, 13.5};
  cout << item.id << ' ' << item.mark << '\n';
}
