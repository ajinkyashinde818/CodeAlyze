#include <iostream>
using namespace std;
int main() {
  int data[] = { 9, 8, 9 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
