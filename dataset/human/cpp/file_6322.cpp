#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  long long p = 1;
  
  string T;
  T.resize(2 * N);
  T[0] = 'L';
  for(int i = 1; i < 2 * N; i++){
    if(S[i - 1] == S[i]){
      if(T[i - 1] == 'L') T[i] = 'R';
      else T[i] = 'L';
    }else{
      T[i] = T[i - 1];
    }
  }
  
  for(int i = 1; i <= N; i++){
    p *= i;
    p %= mod;
  }
  
  if(S[0] == 'W' || S[2 * N - 1] == 'W') p = 0;
  
  int num_of_R = 0;
  for(int i = 2 * N - 1; i >= 0; i--){
    if(T[i] == 'R') num_of_R++;
    else{
      p *= num_of_R;
      p %= mod;
      num_of_R--;
    }
  }
  if(num_of_R) p = 0;
  
  cout << p << endl;
  
  return 0;
}
