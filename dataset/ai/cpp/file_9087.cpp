#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
  vector<int> data{2, 4, 6, 60};
  cout << binary_search(data.begin(), data.end(), 60) << '\n';
}
