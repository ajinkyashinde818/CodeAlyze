#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for_each(begin(a), end(a), [](auto &e) {
    cin >> e;
  });

  const int neg_count = count_if(begin(a), end(a), [](auto e) {
    return e < 0;
  });
  const int zero_count = count_if(begin(a), end(a), [](auto e) {
    return e == 0;
  });
  
  for_each(begin(a), end(a), [](auto &e) {
    e = abs(e);
  });
  if (neg_count % 2 == 0 || (neg_count + zero_count) % 2 == 0) {
    cout << accumulate(begin(a), end(a), 0LL) << endl;
  } else {
    const auto min_val = *min_element(begin(a), end(a));
    cout << accumulate(begin(a), end(a), 0LL) - min_val * 2 << endl;
  }
}
