#include <iostream>
using namespace std;
struct Record { int id; double mark; };
int main() {
  Record item{82, 19.5};
  cout << item.id << ' ' << item.mark << '\n';
}
