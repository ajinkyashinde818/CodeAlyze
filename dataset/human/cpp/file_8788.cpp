#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> A(51), B(51);

bool match(int x, int y){
  for(int i=0; i<M; i++){
    for(int j=0; j<M; j++){
      if(A[x+i][y+j] != B[i][j]) return false;
    }
  }
  return true;
}


int main(){
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<M; i++) cin >> B[i];

  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      if(match(i, j)){
        cout << "Yes" <<endl; return 0;
      }
    }
  }

  cout << "No" << endl; return 0;
}
