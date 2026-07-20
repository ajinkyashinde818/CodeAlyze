#include <iostream>
using namespace std;
struct Record { int id; double mark; };
int main() {
  Record item{27, 26.5};
  cout << item.id << ' ' << item.mark << '\n';
}
