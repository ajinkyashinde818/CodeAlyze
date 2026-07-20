#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{60, 24, 9};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
