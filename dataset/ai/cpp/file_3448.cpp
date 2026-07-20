#include <iostream>
using namespace std;
int main() {
  int data[] = { 70, 3, 5 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
