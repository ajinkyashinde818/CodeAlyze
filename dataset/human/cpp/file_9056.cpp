#include <iostream>
#include <string>
using namespace std;
int main(){
  int M, N;
  int tmp=0,ans=0;
  cin >> N >> M;
  char A[N+1][N+1], B[M+1][M+1];
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> A[i][j];
    }
  }
  for(int i=1;i<=M;i++){
    for(int j=1;j<=M;j++){
      cin >> B[i][j];
    }
  }
  
  for(int i=1;i<=N-M+1;i++){
    for(int j=1;j<=N-M+1;j++){
      tmp = 1;
      for(int k=1;k<=M;k++){
        for(int l=1;l<=M;l++){
          if(A[i+k-1][j+l-1] == B[k][l]){
          }else tmp = 0;          
        }
      }
      if(tmp == 1)ans = 1;
    }
  }
  
  if(ans == 1)cout << "Yes" << endl;
  else cout << "No" << endl;      
  return 0;
}
