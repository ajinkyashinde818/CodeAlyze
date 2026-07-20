#include <iostream>
using namespace std;
int main() {
  int data[] = { 17, 4, 4 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
