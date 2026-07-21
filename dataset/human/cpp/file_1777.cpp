#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;

  std::vector<int> requests;
  for (int i = 0; i < m; ++i) {
    int e;
    cin>>e;
    requests.push_back(e);
  }

  std::set<int> used;
  for (int i = m - 1; i >= 0; --i) {
    if (used.find(requests[i]) == used.end()) {
      cout << requests[i] << endl;
      used.insert(requests[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (used.find(i + 1) == used.end()) {
      cout << i + 1 << endl;
    }
  }
}
