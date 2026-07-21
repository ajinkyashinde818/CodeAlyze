#include<bits/stdc++.h>
using namespace std;

int main(){
int N,M;
  cin>>N>>M;
  char A[N][N], B[M][M];
  for(int i=0; i<N; i++){
   for(int j=0; j<N; j++){
   cin>>A[i][j];}}
  for(int i=0; i<M; i++){
   for(int j=0; j<M; j++){ 
   cin>>B[i][j];}}
  
  for(int i=0; i+M<=N; i++){
   for(int j=0; j+M<=N; j++){
      bool ans=true;
       for(int x=0; x<M; x++){
        for(int y=0; y<M; y++){
         if(A[i+x][j+y]!=B[x][y]){ans=false;}
        }
       }
      if(ans){cout<<"Yes"; return 0;} 
   }
  }
  
  cout<<"No";
}
