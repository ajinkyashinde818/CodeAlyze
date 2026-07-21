#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 2e5+10;
LL a[N];

int main(){
  LL mn = 1LL<<62;
  int n;
  cin >> n;
  LL sum = 0, sum_now = 0 ;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
  }
  LL res = 0;
  for(int i=0;i<n-1;i++){
    sum_now += a[i];
    res = sum - sum_now - sum_now;
    if(res < 0) res = -res;
    mn = min(mn, res);
  }
  cout << mn << endl;
}
