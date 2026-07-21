#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<long long> A(n);
  int m = 1001001001;
  int cnt;
  long long ans = 0;
  
  for(int i = 0; i < n; i++){
    cin >> A.at(i);
    long long tmp = abs(A.at(i));
    ans += tmp;
    if(m > tmp){
      m = tmp;
      cnt = i;
    }
  }
  for(int i = 0; i < cnt; i++){
    if(A.at(i) < 0) A.at(i+1) = -1*A.at(i+1);
  }
  for(int i = n-1; i > cnt; i--){
    if(A.at(i) < 0) A.at(i-1) = -1*A.at(i-1);
  }
  if(A.at(cnt) >= 0) cout << ans << endl;
  else cout << ans + 2 * A.at(cnt) << endl;
}
