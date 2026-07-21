#include<iostream>
using namespace std;
int main(void){
  int n,m;
  cin>>n>>m;
  string*A=new string[n];
  string*B=new string[m];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  for(int i=0;i<m;i++){
    cin>>B[i];
  }
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      bool check=true;
      for(int k=0;k<m;k++){
        for(int l=0;l<m;l++){
          if(A[i+k][j+l]!=B[k][l]){
            check=false;
            break;
          }
        }
        if(!check){
          break;
        }
      }
      if(check){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
