#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{25, 20, 9};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
