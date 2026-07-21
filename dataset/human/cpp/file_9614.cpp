#include <iostream>
using namespace std;
int main(void){
   int N,M;
   cin>>N>>M;
   char A[N][N],B[M][M];
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
   bool check=false;
   for(int i=0;i<=N-M;i++){
       for(int j=0;j<=N-M;j++){
           int count=0;
           for(int k=0;k<M;k++){
               for(int l=0;l<M;l++){
                   if(B[k][l]==A[i+k][j+l]) count++;
               }
           }
           if(count==M*M) check=true;
       }
   }
   if(check==true) {cout<<"Yes";}
   else cout<<"No";
   return 0;
   
}
