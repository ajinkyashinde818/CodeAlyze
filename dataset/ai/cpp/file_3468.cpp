#include <iostream>
using namespace std;
int main() {
  int data[] = { 90, 23, 4 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
