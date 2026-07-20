#include <iostream>
using namespace std;
int main() {
  int data[] = { 34, 2, 6 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
