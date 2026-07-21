#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  int k=0;
  for(int i=1;i*(i-1)<=2*N;i++) {
    if(i*(i-1)==2*N) k=i;
  }
  if(!k) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    cout << k << endl;
    vvi a(k,vi(k-1));
    rep(i,k-1) a[0][i]=i+1;
    rep2(i,1,k) {
      rep(j,i) a[i][j]=a[j][i-1];
      rep2(j,i,k-1) a[i][j]=a[i-1][k-2]+j-i+1;
    }
    rep(i,k) {
      cout << k-1 << ' ';
      rep(j,k-1) {
        cout << a[i][j] << ' ';
      }
      cout << endl;
    }
  }
}
