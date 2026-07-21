#include <bits/stdc++.h>
using namespace std;
 
int main(){
long long N;
  cin >> N;
  long long ans = 0;
  long long d[N];
  long long mi = 1000000010;
  
  for(long long i = 0;i < N;i++){
    cin >> d[i];
    mi = min(mi, abs(d[i]));
  }
    for(long long i = 0;i < N - 1;i++){
    ans += abs(d[i]);
    if(d[i] < 0){
      d[i] = d[i] * (-1);
      d[i + 1] = d[i + 1] * (-1);
  }
  }
  ans += abs(d[N - 1]);
  
  if(d[N - 1] > 0) cout << ans << endl; 
  else cout << ans - 2 * abs(mi) << endl;
  
return 0;
  
}
