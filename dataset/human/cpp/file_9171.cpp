#include<bits/stdc++.h>
using namespace std;
const int maxN=52;
bool a[maxN][maxN],b[maxN][maxN];
int n,m;
int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
      char c;
      cin>>c;
      if(c=='#')a[i][j]=true;
    }
  for(int i=0;i<m;i++)for(int j=0;j<m;j++){
      char c;
      cin>>c;
      if(c=='#')b[i][j]=true;
    }
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      bool f=true;
      for(int k=i;k<i+m;k++){
	for(int l=j;l<j+m;l++){
	  if(a[k][l]!=b[k-i][l-j])f=false;
	}
      }
      if(f){
	cout<<"Yes"<<endl;
	return 0;
      }
    }
  }
  cout<<"No"<<endl;
}
