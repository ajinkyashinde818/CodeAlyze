#include <iostream>
using namespace std;
int main() {
  int data[] = { 38, 21, 9 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
