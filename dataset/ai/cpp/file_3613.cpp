#include <iostream>
using namespace std;
int main() {
  int data[] = { 57, 13, 9 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
