#include <iostream>
using namespace std;
int main() {
  int data[] = { 60, 24, 9 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
