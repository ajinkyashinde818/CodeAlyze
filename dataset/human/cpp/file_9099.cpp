#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector< string > A(N) ,B(M);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  for(int j = 0; j < M; j++){
    cin >> B[j];
  }
  
  bool ans = false;
  for(int xs = 0; xs <= N - M; xs++){
    for(int ys = 0; ys <= N - M; ys++){
      bool clr = true;
      for(int x = 0; x < M; x++){
        for(int y = 0; y < M; y++){
          if(A[x+xs][y+ys] != B[x][y]) clr = false;
        }
      }
      if(clr) ans = true;
    }
  }
  cout << (ans?"Yes":"No") << endl;
}
