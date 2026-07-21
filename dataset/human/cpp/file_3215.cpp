#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, neg = 0, m = 2000000000;
  int64_t S = 0;
  
  cin >> N;
  
  for (int i = 0; i < N; i++){
    cin >> A;
    if (A < 0){
      neg += 1;
    }
    m = min(m, abs(A));
    S += abs(A);
  }
  if (neg % 2 == 1){
    cout << S - 2 * m << endl;
  }
  else{
    cout << S << endl;
  }
}
