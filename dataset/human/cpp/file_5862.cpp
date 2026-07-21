#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n;
  long long c;
  cin >> n >> c;

  vector<long long> x(n + 1), v(n + 1);
  vector<long long> s(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
    s[i] = s[i - 1] + v[i];
  }

  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, s[i] - x[i]);
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, s[n] - s[i - 1] - (c - x[i]));
  }
  
  multiset<long long> st;
  multiset<long long> st2;
  for (int j = 1; j <= n; j++) {
    long long v0 = -s[j - 1] - (c - x[j]);
    long long v1 = -s[j - 1] - (c - x[j]) * 2;
    st.insert(v0);
    st2.insert(v1);
  }
  for (int i = 0; i < n; i++) {
    ans = max(ans, s[i] + s[n] - x[i] * 2 + *st.rbegin());
    ans = max(ans, s[i] + s[n] - x[i] + *st2.rbegin());
    long long v0 = -s[i] - (c - x[i + 1]);
    long long v1 = -s[i] - (c - x[i + 1]) * 2;
    st.erase(st.find(v0));
    st2.erase(st2.find(v1));
  }

  cout << ans << endl;
}
