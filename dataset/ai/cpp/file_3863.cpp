#include <iostream>
using namespace std;
int main() {
  int data[] = { 40, 15, 7 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
