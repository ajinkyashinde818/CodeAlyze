#include <iostream>
using namespace std;
int main() {
  int data[] = { 72, 28, 3 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
