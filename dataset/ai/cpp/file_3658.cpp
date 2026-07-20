#include <iostream>
using namespace std;
int main() {
  int data[] = { 13, 27, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
