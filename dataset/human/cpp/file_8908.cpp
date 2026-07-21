#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  string c = "No";
  cin >> N >> M;
  char a[N][N],b[M][M];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a[i][j];
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin >> b[i][j];
    }
  }
  for(int k=0;k<N-M+1;k++){
    for(int l=0;l<N-M+1;l++){
      int d=0;
      for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(a[i+k][j+l] == b[i][j])
              d++;
         }
      }
      if(d==M*M){
        c = "Yes";
      }
    }
  }
  cout << c << endl;
}
