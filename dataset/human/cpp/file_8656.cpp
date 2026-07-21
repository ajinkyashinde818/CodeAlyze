#include<iostream>

using namespace std;

int main(){

   int N, M;
   cin>> N>> M;
   char a[N][N], b[M][M];
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         cin>> a[i][j];
      }
   }
   for(int i=0; i<M; i++){
      for(int j=0; j<M; j++){
         cin>> b[i][j];
      }
   }

   bool okok=false;
   for(int i=0; i+M-1<N; i++){
      for(int j=0; j+M-1<N; j++){
         bool ok=true;
         for(int k=0; k<M; k++){
            for(int l=0; l<M; l++){
               ok&=a[i+k][j+l]==b[k][l];
            }
         }
         okok|=ok;
      }
   }

   if(okok){
      cout<< "Yes"<< endl;
   }else{
      cout<< "No"<< endl;
   }

   return 0;
}
