/* Standalone example. */
#include <iostream>
using namespace std;
int main() {
  int data[] = { 55, 30, 8 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
