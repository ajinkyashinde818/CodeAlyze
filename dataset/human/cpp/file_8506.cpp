#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n,m;
  cin>>n>>m;
  string a[n],b[m];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];
  bool f=0;
  for(int i=0;i<=n-m;i++){
    for(int j=0;j<=n-m;j++){
      bool ff=1;
      for(int k=0;k<m;k++)
	for(int l=0;l<m;l++)
	  ff&=a[i+k][j+l]==b[k][l];
      f|=ff;
    }
  }
  cout<<(f?"Yes":"No")<<endl;
  return 0;
}
