#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N,M;
 cin >> N >> M;
  vector<vector<char>> A(N, vector<char>(N));
  vector<vector<char>> B(M, vector<char>(M));
  vector<vector<char>> C(M, vector<char>(M));//判別用行列
  
  for(int i = 0;i<N;i++){
    for(int j = 0;j<N;j++){
      cin >> A[i][j];
    }
  }
  for(int i = 0;i<M;i++){
    for(int j = 0;j<M;j++){
      cin >> B[i][j];
    }
  }
  bool flag = false;
  bool flag2 = false;
  for(int i = 0;i<=N-M;i++){
   for(int j = 0;j<=N-M;j++){//左上の点を決めた
     for(int k = i;k<=i+M-1;k++){
       for(int l = j;l<=j+M-1;l++){
        C[k-i][l-j] = A[k][l];
       }
     }
     if(C==B){
       flag = true;
       break;
     }
   }
    if(flag){
      flag2 = true;
      break;
    }
  }
     if(flag2) cout << "Yes" << endl;
     else cout << "No" << endl;
}
