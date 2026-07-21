#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+10;
int n, a[MAXN], b[MAXN];
vector<pair<int,int>> as;
int ans[MAXN];

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> b[i];
  for(int i=0;i<n;i++) {
    as.push_back({a[i], i});
  }
  sort(as.begin(), as.end());
  sort(b, b+n);
  reverse(b, b+n);
  int same = -1;
  int scnt = 0;
  bool pos = true;
  for(int i=0;i<n;i++) {
    if (as[i].first==b[i]) {
      same = b[i];
      scnt++;
    }
  }
  for(int i=0;i<n;i++) {
    ans[as[i].second] = b[i];
  }
  if (same != -1) {
    vector<int> other;
    for(int i=0;i<n;i++) {
      if (as[i].first!=same && b[i]!=same) {
        other.push_back(i);
      }
    }
    if (other.size()<same) pos = false;
    else {
      for(int i=0;i<n;i++) {
        if (as[i].first==b[i]) { // swap this pairing with other.back()
          swap(ans[as[i].second], ans[other.back()]);
          other.pop_back();
        }
      }
    }
  }
  if (pos) {
    cout << "Yes" <<endl;
    for(int i=0;i<n;i++) cout << ans[i] << " "; 
    cout <<endl;
  }
  else {
    cout << "No" <<endl;
  }
}
