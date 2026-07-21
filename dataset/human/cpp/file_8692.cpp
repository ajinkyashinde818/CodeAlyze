#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<vector>

using namespace std;

int s(int i,int j,int m,char a[200][200],char b[200][200])
{
  int k,l;
  for(k=0;k<m;k++)
    for(l=0;l<m;l++)
      if(a[i+k][j+l]!=b[k][l])
        return 0;
  return 1;
}

int main(void)
{
  char a[200][200]={};
  char b[200][200]={};
  int n,m;
  int i,j;

  cin>>n>>m;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf(" %c",&a[i][j]);

  for(i=0;i<m;i++)
    for(j=0;j<m;j++)
      scanf(" %c",&b[i][j]);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(a[i][j]==b[0][0])
        if(s(i,j,m,a,b))
          {
            puts("Yes");
            return 0;
          }
  puts("No");
}
