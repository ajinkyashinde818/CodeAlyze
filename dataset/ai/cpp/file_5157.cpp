#include <iostream>
using namespace std;
class Counter {
  int value;
  public:
  Counter(int start) : value(start) {}
  int get() const { return value; }
};
int main() {
  Counter item(91);
  cout << item.get() << '\n';
}
