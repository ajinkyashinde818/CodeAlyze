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

graph t;

lli n,l;
lli m;
lli ans = 0;

void trytree(string& $,lli node,lli i){
  if(i == $.size()) return;
  for(auto& x : t[node]){
    if(x.second == $[i]) return trytree($,x.first,i+1);
  }
  t[node][m] = $[i];
  m++;
  trytree($,m-1,i+1);
  return;
}

void dfs(lli node,lli d){
  // cout << node << endl;
  if(t[node].size() == 1){
    lli x = 1;
    while((l-d)%x == 0) x <<= 1;
    x >>= 1;
    ans ^= x;
  }
  for(auto& x : t[node]){
    dfs(x.first,d+1);
  }
}

int main(){
  cin >> n >> l;
  m = 1;
  for(lli i = 0;i < n;i++){
    string $;
    cin >> $;
    trytree($,0,0);
  }
  dfs(0,0);
  cout << (ans == 0 ? "Bob" : "Alice") << endl;
}
