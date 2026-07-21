#include<iostream>
using namespace std;

int main(){
  
  int n, m;
  char a[50][51], b[50][51];

  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cin>>b[i][j];
    }
  }


  bool f1=false;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      bool f2=true;
      for(int k=0;k<m;k++){
	for(int l=0;l<m;l++){
	  if(a[i+k][j+l]!=b[k][l]) f2=false;
	}
      }
      if(f2) f1=true;
    }
  }

  if(f1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}
