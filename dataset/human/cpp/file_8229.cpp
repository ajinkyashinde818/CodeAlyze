#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  vector<long long> a(N);
  long long S = 0 ; 
  long long x = 0 ;
  long long ans = 1000000000000000000 ; 
  
  for(int i = 0 ; i < N  ; i++){
    cin >> a.at(i) ; 
    S += a.at(i) ;
  }
  for(int i = 0 ; i < N ; i++){
    x += a.at(i) ; 
    if( i + 1 < N ) ans = min(ans , abs(S - 2*x)) ; 
  }
  
  cout << ans << endl;
}
