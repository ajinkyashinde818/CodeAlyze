#include <iostream>
int main() {
    int data[] = { 66, 18, 9 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
