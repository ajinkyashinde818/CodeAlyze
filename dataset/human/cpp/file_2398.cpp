#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int M = INF;
  long long ans = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++){
    ans += abs(A[i]);
    M = min(M, abs(A[i]));
    if (A[i] < 0){
      cnt++;
    }
  }
  if (cnt % 2 == 0){
    cout << ans << endl;
  } else {
    cout << ans - M * 2 << endl;
  }
}
