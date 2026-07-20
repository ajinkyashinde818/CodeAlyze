#include <iostream>
using namespace std;
int main() {
  int data[] = { 25, 20, 9 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
