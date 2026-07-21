#include <iostream>
#include <string>
using namespace std;
const int MAX = 60;
char A[MAX][MAX],B[MAX][MAX];

int check(int i,int j,int N,int M){ //左上がA[i][j]の場所がBと一致するかチェックする
  for(int k=0;k<M;k++){
    for(int l=0;l<M;l++){
      if(A[i+k][j+l]!=B[k][l]) return 0;
    }
  }
  return 1;
}

int main(){
  int N,M;

  cin >> N >> M;

  if(N < M){ //Bのほうが画像サイズが大きければNo
    cout << "No" << endl;
    return 0;
  }

  for(int i=0;i<N;i++) //入力
    for(int j=0;j<N;j++) cin >> A[i][j];
  for(int i=0;i<M;i++)
    for(int j=0;j<M;j++) cin >> B[i][j];
  
  for(int i=0;i<N-M+1;i++){ //左上の座標がA[i][j]の場所をチェック
    for(int j=0;j<N-M+1;j++){
      if(check(i,j,N,M)){
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
