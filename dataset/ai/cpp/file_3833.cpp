#include <iostream>
using namespace std;
int main() {
  int data[] = { 10, 16, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
