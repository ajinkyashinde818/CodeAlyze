#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{31, 14, 9};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
