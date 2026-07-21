#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,j,p,q,n,m;
  char N[50][50], M[50][50];
  cin>>n>>m;
  for(i=0; i<n; i++) cin>>N[i];
  for(i=0; i<m; i++) cin>>M[i];
  for(i=0; i+m<=n; i++){
    for(j=0; j+m<=n; j++){
      for(p=0; p<m; p++){
        for(q=0; q<m; q++){
          if(N[i+p][j+q]!=M[p][q]) break;
        }
        if(q<m) break;
      }
      if(p==m && q==m){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
