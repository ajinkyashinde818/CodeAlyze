#include<iostream>
#include<string>
using namespace std;


int main(){
  int N,M;
  cin >> N;
  cin >> M;

  int A[N][N];
  int B[M][M];

  for(int i = 0; i < N ; i++){
    string str;
    cin >> str;
    for(int j = 0; j < N; j++){
      if(str[j]=='#'){
        A[i][j] = 0;
      }else{
        A[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < M ; i++){
    string str;
    cin >> str;
    for(int j = 0; j < M; j++){
      if(str[j]=='#'){
        B[i][j] = 0;
      }else{
        B[i][j] = 1;
      }
    }
  }


  bool result = false;
  for(int i=0;i<=(N-M);i++){


    for(int j=0;j<=(N-M);j++){
      bool flag = true;

      for(int k=i;k<(i+M);k++){
        for(int l=j;l<(j+M);l++){
            //cout << endl;
            //cout << i << endl << j << endl << k << endl << l <<endl;
          if(A[k][l]!=B[k-i][l-j]){
            flag = false;
          }
        }
      }

      if(flag == true){
        result = true;
      }
    }


  }

  if(result == true){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
