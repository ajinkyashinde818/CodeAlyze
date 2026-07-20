#include <iostream>
using namespace std;
int main() {
  int data[] = { 91, 20, 3 };
  int sum = 0;
  for (int item : data) sum += item;
  cout << sum << '\n';
}
