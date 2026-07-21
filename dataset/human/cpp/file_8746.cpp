#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (int i=0; i<N; i++) {
      cin >> A.at(i);
  }
  for (int i=0; i<M; i++) {
      cin >> B.at(i);
  }
  bool finished=false;
  bool finishedd=false;
  for (int i=0; i<=N-M; i++) {
      for (int j=0; j<=N-M; j++) {
          for (int k=0; k<M; k++) {
              for (int l=0; l<M; l++) {
                  if (A.at(i+k).at(j+l)!=B.at(k).at(l)) {
                      finished=true;break;
                  }
              }
              if(finished) {
                  finished=false;break;
              }
              if (k==M-1) {
                  finishedd=true;
              }
          }
      }
  }
  if (finishedd) cout << "Yes" << endl;
  else cout << "No" << endl;
}
