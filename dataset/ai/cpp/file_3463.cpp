#include <iostream>
using namespace std;
int main() {
  int data[] = { 85, 18, 6 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
