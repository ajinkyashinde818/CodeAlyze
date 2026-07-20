#include <iostream>
using namespace std;
int main() {
  int data[] = { 82, 7, 6 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
