#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{43, 11, 8};
  sort(data.begin(), data.end());
  cout << data.front() << '\n';
}
