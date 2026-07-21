#include <bits/stdc++.h>
using namespace std;
int n,m;
string A[101],B[101];

bool check(int x,int y){
  if(x+m-1>=n||y+m-1>=n) return 0;
  for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
      if(A[y+i][x+j] != B[i][j]) return 0;

      return 1;
}

int main(){
  cin>>n>>m;


  for(int i=0;i<n;i++) cin>>A[i];
  for(int i=0;i<m;i++) cin>>B[i];
  

  int ans=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)if(check(j,i)) ans=1;

  cout<<(ans?"Yes":"No")<<endl;
  return 0;
}
