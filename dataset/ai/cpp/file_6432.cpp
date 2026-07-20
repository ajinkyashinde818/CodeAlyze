#include <iostream>
class Base { public: virtual int value() const { return 1; } };
class Derived : public Base { public: int value() const override { return 91; } };
int main() {
	Derived item; std::cout << item.value() << '\n';
}
