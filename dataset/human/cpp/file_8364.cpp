#include<bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<char>> A(50, vector<char>(50)), B(50, vector<char>(50));

bool Tmatch(int x, int y){
 
  int i, j;
  for(i=0; i<M; i++){
    for(j=0; j<M; j++){
      if(B[i][j]!=A[x+i][y+j]){
        return false;
      }
    }
  }
  return true;
}

int main(){

  int i, j;
  cin>>N>>M;
  
  for(i=0;i<N;i++){for(j=0;j<N;j++)cin>>A[i][j];}
  for(i=0;i<M;i++){for(j=0;j<M;j++)cin>>B[i][j];}

  for(i=0;i<N-M+1;i++){
    for(j=0;j<N-M+1;j++){
      if(Tmatch(i, j)==true){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
