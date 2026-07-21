#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include <stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<array>
#include<vector>
#include<set>
#include <utility>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int r,g,b,n;
  cin >>r>>g>>b>>n;
  int ans=0;
  rep(i,n+1){
    rep(j,n+1){
      int s=n-i*r-j*g;
      if(s>=0 && s%b==0) ans++;
    }

  }
  cout <<ans<<endl;
}
