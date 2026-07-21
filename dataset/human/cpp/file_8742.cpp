#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, a=0;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i=0; i<N; i++) cin >> A.at(i);
  for (int i=0; i<M; i++) cin >> B.at(i);
  for (int i=0; i<N-(M-1); i++){
    for (int j=0; j<N-(M-1); j++){
      for (int k=0; k<M; k++){
        if(A.at(i+k).substr(j,M)!=B.at(k)) break;
        if(k==M-1) a=1;
      }
    }
  }
  if (a==1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
