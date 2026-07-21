#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <string>
#include <random>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int mod = 1000000007;

int p[maxn];

int main() {
#ifdef suiyuan2009
  freopen("/Users/suiyuan2009/CLionProjects/icpc/input.txt", "r", stdin);
  //freopen("/Users/suiyuan2009/CLionProjects/icpc/output.txt", "w", stdout);
#endif
  p[0]=1;
  for(int i=1;i<maxn;i++)p[i]=p[i-1]*2%mod;
  int n;
  string s;
  cin>>n>>s;
  vector<int>c=vector<int>(26,0);
  for(int i=0;i<n;i++)c[s[i]-'a']++;
  ll ret = 1;
  for(int i=0;i<26;i++)ret=ret*(c[i]+1)%mod;
  ret = (ret+mod-1)%mod;
  cout<<ret<<endl;
  return 0;
}
