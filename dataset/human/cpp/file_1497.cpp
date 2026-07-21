#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli n;
mat ans;

void error(){
  cout << "No" << endl;
  exit(0);
}

int main(){
  cin >> n;
  lli k = 1;
  for(;(k*k-k)/2 < n;k++);
  if((k*k-k)/2 != n) error();
  ans = mat(k);
  lli j = 0;
  lli s = 1;
  for(lli i = 1;i <= n;i++){
    // cout << j << " " << j+s << endl;
    ans[j].push_back(i);
    ans[j+s].push_back(i);
    s++;
    if(ans[j].size() == k-1) j++;
    if(j+s >= k) s = 1;
  }
  cout << "Yes" << endl;
  cout << k << endl;
  for(lli i = 0;i < k;i++){
    cout << ans[i].size();
    for(lli x : ans[i]) cout << " " << x;
    cout << endl;
  }

}
