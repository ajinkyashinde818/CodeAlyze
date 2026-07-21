#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  char m1[55][55],m2[55][55];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>m1[i][j];
  for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
      cin>>m2[i][j];
  int f=0;
  for(int i=0;i<=n-m;i++)
    for(int j=0;j<=n-m;j++){
      int tmp=1;
      for(int x=0;x<m;x++)
	for(int y=0;y<m;y++)
	  if(m1[x+i][y+j]!=m2[x][y])tmp=0;
      f+=tmp;
    }
  cout<<(f?"Yes":"No")<<endl;
  return 0;
}
