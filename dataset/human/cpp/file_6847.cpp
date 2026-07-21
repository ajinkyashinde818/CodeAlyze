#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
    A[i]--;
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++){
    cin >> B[i];
    B[i]--;
  }
  vector<int> cntA(N, 0);
  for (int i = 0; i < N; i++){
    cntA[A[i]]++;
  }
  vector<int> cntB(N, 0);
  for (int i = 0; i < N; i++){
    cntB[B[i]]++;
  }
  bool ok = true;
  for (int i = 0; i < N; i++){
    if (cntA[i] + cntB[i] > N){
      ok = false;
    }
  }
  if (!ok){
    cout << "No" << endl;
  } else {
    vector<int> C;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < max(cntA[i], cntB[i]); j++){
        C.push_back(i);
      }
    }
    int M = C.size();
    vector<int> D;
    for (int i = M / 2; i < M; i++){
      D.push_back(C[i]);
    }
    for (int i = 0; i < M / 2; i++){
      D.push_back(C[i]);
    }
    vector<int> ans;
    for (int x : D){
      if (cntB[x] > 0){
        ans.push_back(x);
        cntB[x]--;
      }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N; i++){
      cout << ans[i] + 1;
      if (i < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}
