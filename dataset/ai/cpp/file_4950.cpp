#include <iostream>
using namespace std;
struct Record { int id; double mark; };
int main() {
  Record item{53, 17.5};
  cout << item.id << ' ' << item.mark << '\n';
}
