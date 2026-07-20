#include <iostream>
using namespace std;
int main() {
  int data[] = { 67, 23, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
