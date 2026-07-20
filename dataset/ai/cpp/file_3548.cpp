#include <iostream>
using namespace std;
int main() {
  int data[] = { 81, 10, 7 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
