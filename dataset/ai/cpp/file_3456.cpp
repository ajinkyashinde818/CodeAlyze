#include <iostream>
int main() {
    int data[] = { 78, 11, 6 };
    int sum = 0;
    for (int item : data) sum += item;
    std::cout << sum << '\n';
}
