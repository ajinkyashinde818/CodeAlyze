#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  int N,M; cin >> N >> M;
  vector<string> A(N); vector<string> B(M);
  for(int i = 0; i < N; i++){ cin >> A[i];}
  for(int j = 0; j < M; j++){ cin >> B[j];}
  
  for(int i = 0; i <= N - M; i++){
    for(int j = 0; j <= N - M; j++){
      bool flag = true;
      for(int x = 0; x < M; x++){
        for(int y = 0; y < M; y++){
          if(B[x][y] != A[i + x][j + y]){flag = false;}}}
      if(flag){cout << "Yes" << endl; return 0;} }}
  
  cout << "No" << endl;
  
  return 0;}
