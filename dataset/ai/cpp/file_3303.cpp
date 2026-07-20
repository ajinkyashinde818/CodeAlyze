#include <iostream>
using namespace std;
int main() {
  int data[] = { 14, 13, 7 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
