#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<vector<char>> I(N, vector<char>(N,'x'));
  vector<vector<char>> P(M, vector<char>(M,'x'));
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++) cin >> I[i][j];
  }
  
  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++) cin >> P[i][j];
  }
  bool f = false;
  for(int sx = 0; sx < N-M+1; sx++){
    for(int sy = 0; sy < N-M+1; sy++){
      f = true;
      for(int i = 0; i < M; i++){
        for(int j = 0; j < M;j++){
          if(I[sx+i][sy+j] != P[i][j]){
            f = false;
          }
        }
      }
      if(f) break;
    }
    if(f)break;
  }
  if(f) cout << "Yes";
  else cout << "No";
}
