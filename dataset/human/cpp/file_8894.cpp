#include <bits/stdc++.h>
using namespace std;
int M,N;
char A[50][50],B[50][50];
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin >> B[i][j];
    }
  }
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      int count=0;
      for(int k=i;k<=i+M-1;k++){
        for(int l=j;l<=j+M-1;l++){
          if(A[k][l]==B[k-i][l-j]) count++;
          //cout << count << endl;
        }
      }
      if(count==M*M){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
