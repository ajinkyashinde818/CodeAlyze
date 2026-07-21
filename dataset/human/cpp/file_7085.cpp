#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void print_vec(const vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &an: a) cin >> an;
  for (auto &bn: b) cin >> bn;
  reverse(b.begin(), b.end());
  vector<int> same;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) same.push_back(i);
  }
  int cnt = same.size();
  if (cnt == 0) {
    cout << "Yes\n";
    print_vec(b);
    return 0;
  }

  int val = b[same[0]];
  vector<int> exchange;
  for (int i = 0; i < n; ++i) {
    if (a[i] != val && b[i] != val && cnt > 0) {
      exchange.push_back(i);
      --cnt;
    }
  }
  if (cnt > 0) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < (int)same.size(); ++i) {
    swap(b[same[i]], b[exchange[i]]);
  }
  cout << "Yes\n";
  print_vec(b);

  return 0;
}
