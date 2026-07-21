typedef long long ll; using namespace std;
int m = 1e9+7;
#include <iostream>

int main(){
  int n; cin >> n;
  string s; cin >> s;
  if (s[0] == 'W' || s[2*n-1] == 'W') return 0*puts("0");
  ll a[2] = {1,0}, al[2] = {1,0}, ls=0; bool ok = true; ll an=1;
  for(int i=1; i<2*n && ok; i++) {
    //cout << (s[i] != s[i-1]) << endl;
    if (s[i] != s[i-1]) {
      a[ls]++; al[ls]++;
      if (ls == 1) {
        if (a[0] == 0) ok=0;
        else {an = an * a[0] % m; a[0]--;}
      }
    } else {
      ls^=1;
      a[ls]++; al[ls]++;
      if (ls == 1) {
        if (a[0] == 0) ok=0;
        else {an = an * a[0] % m; a[0]--;}
      }
    }
  }
  //cout << al[0] << " " << al[1] << endl;
  if (al[0]!=al[1]) return 0*puts("0");
  for(int i=1; i<=n; i++) {
    an = an * i % m;
  }
  cout << an << endl;
}
