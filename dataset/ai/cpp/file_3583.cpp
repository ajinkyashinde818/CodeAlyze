#include <iostream>
using namespace std;
int main() {
  int data[] = { 27, 14, 7 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
