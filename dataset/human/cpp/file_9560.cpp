#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  char a[50][50],b[50][50];
  for(int i=0;i<N;i++) for(int j=0;j<N;j++)cin>>a[i][j];
  for(int i=0;i<M;i++) for(int j=0;j<M;j++)cin>>b[i][j];

  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool flg=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(a[i+k][j+l]!=b[k][l]) flg=false;
        }
      }
      if(flg){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
cout<<"No"<<endl;
}
