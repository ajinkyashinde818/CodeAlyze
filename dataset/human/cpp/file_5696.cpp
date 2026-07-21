#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ull>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long ll;
typedef long double ld;
using namespace std;

long long N, L;
ll get_g(ll x){
  if(x==0) return 0;
  ll ret = 1;
  while(x%2==0) x/=2, ret*=2;
  return ret;
}

struct node{
  map<char, node*> nx;
};

ll dfs(node* now, ll d){
  ll ret = 0;
  if(now->nx.size()==0) return 0;
  if(now->nx.size()==1) ret ^= get_g(d);
  for(auto itr=now->nx.begin();itr!=now->nx.end();itr++) {
    ret ^= dfs((*itr).second, d-1);
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  std::cin >> N >> L;
  node st;
  string s;
  vector<node> l(100000);
  ll cnt = 0;

  for(int i=0;i<N;i++){
    std::cin >> s;
    node* now = &st;
    for(int j=0;j<s.size();j++){
      if(now->nx.find(s[j])==now->nx.end()) {
        cnt++;
        now->nx.emplace(s[j], &l[cnt]);
        now = &l[cnt];
      }else{
        now = now->nx.at(s[j]);
      }
    }
  }
  std::cout << (dfs(&st, L)?"Alice":"Bob") << '\n';
  return 0;
}
