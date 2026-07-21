#include<bits/stdc++.h>
using namespace std;

int main(){
  long n,b = 0,w = 0;
  cin >> n;
  string s;
  cin >> s;
  bool ok = false;
  if(s.at(0) == 'B' && s.at(2*n-1) == 'B') ok = true;
  for(long i = 0;i < 2*n;i++){
    if(i % 2 == 0){
      if(s.at(i) == 'W'){
        s.at(i) = 'B';
      }
      else{
        s.at(i) = 'W';
      }
    }
    if(s.at(i) == 'B') b++;
    if(s.at(i) == 'W') w++;
  }
  //cout << s << endl;
  long left = 0,right = 0,ans = 1,inf = 1000000007;
  if(ok == true && b == w){
    for(long i = 0;i < 2*n;i++){
      if(s.at(i) == 'W'){
        left++;
      }
      else{
        //cout << left-right << endl;
        ans *= left-right;
        ans %= inf;
        right++;
      }
    }
  }
  else{
    ans = 0;
  }
  //cout << ans << endl;
  for(long i = 1;i <= n;i++){
    ans *= i;
    ans %= inf;
  }
  cout << ans << endl;
}
