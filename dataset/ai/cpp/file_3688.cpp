#include <iostream>
using namespace std;
int main() {
  int data[] = { 43, 26, 7 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
