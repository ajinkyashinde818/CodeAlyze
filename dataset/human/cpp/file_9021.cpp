#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n,m; cin >>n>>m;

  char a[50][50],b[50][50];
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cin >>a[i][j];
  for(int i=0;i<m;i++)
  for(int j=0;j<m;j++)
  cin >>b[i][j];

  bool exist = false;
  for(int y=0; y<n;y++){
    for(int x=0;x<n;x++){
      if(y+m-1 >=n|| x+m-1>=n ) continue;

      bool match =true;

      for(int yy=0 ; yy<m;yy++){
        for(int xx=0; xx<m;xx++){
          if(a[y+yy][x+xx]!=b[yy][xx]) match = false;
        }
      }
      if( match ) exist = true;
    }
  }
  if(exist) cout  <<"Yes"<<endl;

  else cout <<"No"<<endl;


  }
