#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,M;
   cin>>N>>M;
   vector<vector<char>> A(N,vector<char>(N));
   vector<vector<char>> B(M,vector<char>(M));
   for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
         cin>>A[i][j];
      }
   }
   for(int i=0;i<M;i++){
      for(int j=0;j<M;j++){
         cin>>B[i][j];
      }
   }
   for(int dx=0;dx<N;dx++){
      for(int dy=0;dy<N;dy++){
         if(dx+M-1>N-1||dy+M-1>N-1) continue;
         bool flag=true;
         for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
               if(A[dx+i][dy+j]!=B[i][j]){
                  flag=false;
                  break;
               }
            }
         }
         if(flag){
            cout<<"Yes"<<endl;
            return 0;
         }
      }
   }
   cout<<"No"<<endl;
   return 0;
}
