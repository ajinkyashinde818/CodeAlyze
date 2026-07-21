#include <bits/stdc++.h>

using namespace std;

int main(){

  int n,m;
  cin>>n>>m;

  char A[n][n];
  char B[n][n];
  bool prtN=true;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){ 
      cin>>A[i][j];
    }
  }
  
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){ 
      cin>>B[i][j];
    }
  }

  for(int ay=0; ay<n-m+1; ay++){
    for(int ax=0; ax<n-m+1; ax++){
      bool judge=false;
      for(int by=0; by<m; by++){
        if(by!=0 and judge==false){
          break;
        }
        for(int bx=0; bx<m; bx++){
          if(A[ay+by][ax+bx]==B[by][bx]){
            judge=true;
          }else{
            judge=false;
            break;
          }
        }
      }
      if(judge and prtN==true){
        cout<<"Yes"<<endl;
        prtN=false;
      }
    }
  }

  if(prtN) cout<<"No"<<endl;


}
