#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<string> A(N), B(M);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  for (int i = 0; i < M; i++){
    cin >> B.at(i);
  }
  
  for (int i = 0; i <= N - M; i++){
    for (int j = 0; j <= N - M; j++){
      int test = 0;
      while (A.at(i + test).substr(j, M) == B.at(test)){
        test++;
        if (test == M){
          cout << "Yes" << endl;
          exit(0);
        }
      }
    }
  }
  
  cout << "No" << endl;
}
