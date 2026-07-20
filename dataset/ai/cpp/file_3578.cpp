#include <iostream>
using namespace std;
int main() {
  int data[] = { 22, 9, 9 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
