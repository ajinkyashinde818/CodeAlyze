#include <iostream>
using namespace std;
class Base { public: virtual int value() const { return 1; } };
class Derived : public Base { public: int value() const override { return 54; } };
int main() {
  Derived item; cout << item.value() << '\n';
}
