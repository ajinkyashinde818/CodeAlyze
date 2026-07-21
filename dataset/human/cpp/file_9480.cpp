#include <bits/stdc++.h>
using namespace std;

int main(){
int N, M, cnt;
  cin >> N >> M;
char n[N][N] = {};
char m[M][M] = {};  
bool a = false;  
  
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
    cin >> n[i][j];  
  }
  }

  for(int i = 0;i < M;i++){
    for(int j = 0;j < M;j++){
    cin >> m[i][j]; 
  }
  }
  
  for(int i = 0;i <= N - M;i++){
    for(int j = 0;j <= N - M;j++){
      cnt = 0;
      for(int k = 0;k < M;k++){
        for(int l = 0;l < M;l++){ 
          if(n[i+k][j+l] == m[k][l]) cnt++;   
  }          
  }  
      if(cnt == M * M){ 
            a = true;
            break;
      }
  }
  }
  

  if(a) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
