#include <iostream>
using namespace std;
int main() {
  int data[] = { 59, 27, 3 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
