#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M; 
  cin >> N >> M;
  char A[50][50],B[50][50];
 for(int i=0;i<N;++i){ 
   for(int j=0;j<N;++j)
      cin >> A[i][j]; 
 }
    

 for(int i=0;i<M;++i){
   for(int j=0;j<M;++j)
     cin >> B[i][j];
 }
   bool abcde =false;
  for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
           if(i+M-1>=N or j+M-1>=N) continue;
            bool abc=true;
            for(int h=0;h<M;h++){
                for(int k=0;k<M;k++){
                    if(A[i+h][j+k]!=B[h][k]){
                        abc = false;                                                
                    }
                }
            }
              if(abc) abcde =true;
            
        }
  }
            if(abcde){
                cout<<"Yes"<< endl;
                return 0;
            }
        
    
  else{
    cout<<"No"<< endl;
    return 0;
  }
}
