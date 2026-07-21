#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int mpn[n][n];
  int mpm[m][m];
  bool b=false;
  char a;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a;
      if(a=='#') mpn[i][j]=1;
      if(a=='.') mpn[i][j]=0;
    }
  }
 
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cin>>a;
      if(a=='#') mpm[i][j]=1;
      if(a=='.') mpm[i][j]=0;
    }
  }
 
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      if(mpn[i][j]==mpm[0][0]){
	b=true;
	for(int k=0;k<m;k++){
	  for(int l=0;l<m;l++){
	    if(mpn[i+k][j+l]!=mpm[k][l]){
	      b=false;
	      break;
	    }
	  }
	    if(!b) break;
	}
      }
      if(b) break;
    }
    if(b) break;
  }
  if(b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
