//   _/                _/                 _/_/_/   _/
//_/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
// _/     _/    _/   _/     _/    _/  _/_/_/     _/
//_/     _/    _/   _/     _/    _/  _/    _/   _/
// _/_/   _/_/       _/_/   _/_/      _/_/     _/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const double pi=acos(-1);
const int inf=1e9;
const ll INF=1e18;
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  int m,n,cnt;
  string s[55]={},t[55]={};
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    cin >> s[i];
  }
  for(int i=0; i<m; i++) {
    cin >> t[i];
  }
  for(int i=0; i<n-m+1; i++) {
    for(int j=0; j<n-m+1; j++) {
      if(s[i][j]==t[0][0]) {
        cnt=0;
        for(int k=0; k<m; k++) {
          for(int l=0; l<m; l++) {
            if(t[k][l]==s[i+k][j+l]) {
              cnt++;
            }
          }
        }
        if(cnt==m*m) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
