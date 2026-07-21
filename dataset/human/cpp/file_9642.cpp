#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  string a[100],b[100];
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  int cnt=0;
  bool flag;
  for(int i=0;i<m;i++){
    flag=false;
    for(int j=0;j<a[i].size();j++){
      if(flag){
	break;
      }
      if(a[i][j]==b[i][0]){
	for(int k=0;k<b[i].size();k++){
	  if(a[i][j+k]!=b[i][k]){
	    break;
	  }
	  if(k==b[i].size()-1){
	    cnt++;
	    flag=true;
	  }
	}
      }
    }
  }
  if(cnt==m){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
      
  return 0;
}
