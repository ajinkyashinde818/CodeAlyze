#include <iostream>
using namespace std;
int main() {
  int data[] = { 50, 14, 6 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
