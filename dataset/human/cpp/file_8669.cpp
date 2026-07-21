#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,a[50][50]={},b[50][50]={};
  cin>>n>>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char temp;
      cin>>temp;
      if(temp == '#'){
	a[i][j] = 1;
      }else{
	a[i][j] = 2;
      }
    }
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      char temp;
      cin>>temp;
      if(temp == '#'){
	b[i][j] = 1;
      }else{
	b[i][j] = 2;
      }
    }
  }
  bool next;
  for(int i=0; i<n-m+1; i++){
    for(int j=0; j<n-m+1; j++){
      next=false;
      for(int c=0; c<m; c++){
	for(int d=0; d<m; d++){
	  if(a[i+c][j+d]!=b[c][d]){
	    next=true;
	    break;
	  }
	}
	if(next)break;
      }
      if(!next){
	cout<<"Yes"<<endl;
	return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
