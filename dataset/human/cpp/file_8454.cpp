#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll inf = numeric_limits<ll>::max()/3;

int n,m;
vector< string > a(n);
vector< string > b(m);

bool ok(int p,int q){
  for(int i = 0;i < m;++i){
    for(int j = 0;j < m;++j){
      if(b[i][j] == '#' && a[p+i][p+j] == '.')
        return false;
    }
  }
  return true;
}


int main(void){
  cin >> n >> m;
  a.clear();b.clear();
  a.resize(n);b.resize(m);
  for(int i = 0;i < n;++i){
    cin >> a[i];
  }
  for(int i = 0;i < m;++i){
    cin >> b[i];
  }
  for(int p = 0;p + m - 1 < n;++p){
    for(int q = 0;q + m - 1 < n;++q){
      if(ok(p,q)){
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
