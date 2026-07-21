#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long n;
  cin >> n;
  long t;
  vector<long> v;
  long long ans = 0;
  long minus = 0;
  long minn = powl(10 , 9) ;
  for ( int i = 0; i < n ; i++){
      cin >> t;
      if (t < 0){
        minus += 1;
        ans -= t;
        minn = min(minn , -t);
      }else{
        ans += t;
        minn = min(minn , t);
      }
  }
  if (minus % 2 == 1){
    ans -= (minn * 2);
  }
  cout << ans <<  endl;  
}
