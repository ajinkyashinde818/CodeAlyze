#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
 
const double TL = 1.5 * CLOCKS_PER_SEC;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define clr(x, y) memset(x, y, sizeof(x))
#define forn(i, n) for (int i = 0; i < n; i++)
#define LL long long
const double pi = acos(-1.0);


int n;
int a[200005], b[200005];

int main() {
#ifdef LOCAL
  auto start_clock = clock();
  freopen("in", "r", stdin);
#endif
  scanf("%d", &n);
  map<int, int> ma;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ma[a[i]] += 1;
  }
  map<int, int> mb;
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    mb[b[i]] += 1;
  }

  map<int, pair<int, int>> mp;
  set<pair<int, int>> st;
  for (auto iter : mb) {
    int x = iter.first;
    mp[x] = {iter.second, ma[x]};
    st.insert({min(iter.second, ma[x]), x});
  }

  bool flag = true;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    bool find = false;
    auto iter = st.end();
    int x = a[i];
    while (iter != st.begin()) {
      iter--;
      if (iter->second != x) {
        find = true;
        break;
      }
    } 
    if (!find) {
      flag = false;
      break;
    }
    int y = iter->second;
    ans[i] = y;
    st.erase(iter);
    mp[y].first -= 1;
    //printf("%d %d\n", y, mp[y].first);
    if (mp[y].first > 0) {
      st.insert({min(mp[y].first, mp[y].second), y});
    }

    int w = min(mp[x].first, mp[x].second);
    st.erase({w, x});
    if (mp[x].second > 0) {
      mp[x].second -= 1;
    }
    if (mp[x].first > 0) {
      st.insert({min(mp[x].first, mp[x].second), x});
    }
  }
  if (flag) {
    puts("Yes");
    for (int i = 0; i < n; i++) {
      printf("%d", ans[i]);
      if (i != n - 1) {
        printf(" ");
      }
    }
    puts("");
  } else {
    puts("No");
  }
 
 
#ifdef LOCAL
 auto end_clock = clock();
 cout << "Time:" << (end_clock - start_clock) * 1.0 / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}
