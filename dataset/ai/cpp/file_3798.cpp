#include <iostream>
using namespace std;
int main() {
  int data[] = { 64, 12, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
