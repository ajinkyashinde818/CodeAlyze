#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main() {
  long long N;
  string S;
  cin >> N >> S;
  N *= 2;
  if(S[0] == 'W' || S[N-1] == 'W'){
    cout << 0 << endl;
    return 0;
  }
  vector<long long> A(N);
  A[0] = 1;
  char past = 'B';
  for(int i = 1; i < N; i++){
    if(past == 'B'){
      if(S[i] == 'B'){
        if(A[i-1] == 1) A[i] = -1;
        else if(A[i-1] == -1) A[i] = 1;
        past = 'B';
      }
      else if(S[i] == 'W'){
        if(A[i-1] == -1) A[i] = -1;
        else if(A[i-1] == 1) A[i] = 1;
        past = 'W';
      }
    }
    else if(past == 'W'){
      if(S[i] == 'W'){
        if(A[i-1] == 1) A[i] = -1;
        else if(A[i-1] == -1) A[i] = 1;
        past = 'W';
      }
      else if(S[i] == 'B'){
        if(A[i-1] == -1) A[i] = -1;
        else if(A[i-1] == 1) A[i] = 1;
        past = 'B';
      }
    }
  }

  long long res = 1;
  long long large = 1000000007;
  long long cnt = 0;
  for(int i = 0; i < N; i++){
    if(A[i] == -1){
      res *= i - cnt * 2;
      res %= large;
      cnt++;
    }
  }
  if(cnt != N/2){
    cout << 0 << endl;
    return 0;
  }
  N /= 2;
  for(; N >= 1; N--){
    res *= N;
    res %= large;
  }
  
  cout << res << endl;
}
