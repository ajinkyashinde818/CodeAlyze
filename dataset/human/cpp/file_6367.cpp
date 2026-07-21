#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> vec(2*N,0); //左側が0、右側が1
  for(int i=1; i<2*N; i++){
    if(S[i] == S[i-1]){
      vec[i] = 1 - vec[i-1];
    }
    else{
      vec[i] = vec[i-1];
    }
  }
  
  bool flag = true;
  int64_t ans = 1;
  int64_t MOD = 1e9+7;
  int L = 0;
  for(int i=0; i<2*N; i++){
    if(vec[i] == 0){
      L++;
    }
    else{
      ans *= L;
      L--;
      ans %= MOD;
    }
  }
  if(L != 0 || S[0] == 'W'){
    flag = false;
  }
  
  for(int i=0; i<N; i++){
    ans *= i+1;
    ans %= MOD;
  }
  
  if(flag){
    cout << ans << endl;
  }
  else{
    cout << 0 << endl;
  }
}
