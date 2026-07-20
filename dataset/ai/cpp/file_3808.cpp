/* Standalone example. */
#include <iostream>
using namespace std;
int main() {
  int data[] = { 74, 22, 8 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
