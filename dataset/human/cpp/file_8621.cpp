#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,i,j,k,l;
  int x=0;
  cin >> N >> M;
  vector<vector<char>> A(N,vector<char>(N));
  vector<vector<char>> B(M,vector<char>(M));
  vector<vector<char>> X(M,vector<char>(M));
  for(i=0; i<N; i++){
    for(j=0; j<N; j++) cin >> A.at(i).at(j);
  }
  for(i=0; i<M; i++){
    for(j=0; j<M; j++) cin >> B.at(i).at(j);
  }
  for(i=0; i<N-M+1; i++){
    for(j=0; j<N-M+1; j++){
      for(k=0; k<M; k++){
        for(l=0; l<M; l++) X[k][l] = A[i+k][j+l];
      }
      if(B == X){
        x++;
        break;
      }
    }
  }
  if(x>0) cout << "Yes" << endl;
  else cout << "No" << endl;
}
