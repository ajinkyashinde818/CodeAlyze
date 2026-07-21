#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define repi(start,end) for(int i=start; i<end; i++)
#define repj(start,end) for(int j=start; j<end; j++)
#define repk(start,end) for(int k=start; k<end; k++)
#define repl(start,end) for(int l=start; l<end; l++)
#define RE return 0;

long long x[100002];
int v[100002];
long long a[100002];
long long b[100002];

int main() {
  int n;
  ll c,ans=0;
  cin>>n>>c;
  
  x[0]=0;
  v[0]=0;

  repi(1, n+1) cin>>x[i]>>v[i];
  
  x[n+1]=c;
  v[n+1]=0;
  
  repi(1, n+1) a[i]=a[i-1]+v[i]-(x[i]-x[i- 1]);
  repi(1, n+1) a[i]=max(a[i], a[i-1]);
  
  for (int i=n; i>=1; i--) b[i] = b[i+1]+v[i]-(x[i+1]-x[i]);
  for (int i=n; i>=1; i--) b[i] = max(b[i], b[i+1]);
  
  //cout<<"b["<<1<<"]: "<<b[1]<<en
  repi(1, n+1) {
    ans=max(ans, a[i]);
    ans=max(ans, a[i]-x[i]+b[i+1]);
    //cout<<"    3  : "<<a[i]-x[i]+b[i+1]<<en
    ans=max(ans, b[i]);
    //cout<<"    2   b["<<i<<"]: "<<b[i]<<en
    ans=max(ans, b[i]-(c-x[i])+a[i-1]);
    //cout<<"    4  : "<<b[i]-(c-x[i])+a[i-1]<<en
  }
  
  cout<<ans<<en
  
  RE
}
