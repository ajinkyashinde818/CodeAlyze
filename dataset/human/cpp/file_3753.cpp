/*
By Tianyi Chen. All rights reserved.
Date: 2016-11-25
*/
#include<bits/stdc++.h>
using namespace std;
int n;
using ld=long double;
inline ld sqr(ld x) { return x*x; }
struct ck {
 ld x,y,r;
 void read() {
  cin>>x>>y>>r;
 }
 ld cdis(const ck&b)const {
  return max(ld(0),sqrt(sqr(x-b.x)+sqr(y-b.y))-r-b.r);
 }
}c[1111];
ld dis[1111][1111],d[1111];
queue<int>q;
int main() {
 ios::sync_with_stdio(0);
 cin>>c[0].x>>c[0].y;
 cin>>c[1].x>>c[1].y;
 cin>>n;
 for(int i=2;i<n+2;++i)c[i].read();
 int m=n+2;
 fill(d,d+1111,1e50);
 d[0]=0;
 for(int i=0;i<m;++i)for(int j=0;j<i;++j) {
  dis[i][j]=dis[j][i]=c[i].cdis(c[j]);
 }
 q.push(0);
 while (q.size()) {
  int p=q.front();q.pop();
  for(int i=0;i<m;++i) {
   ld nd=d[p]+dis[p][i];
   if (nd<d[i]) {
    d[i]=nd;
    q.push(i);
   }
  }
 }
 cout<<setprecision(20)<<d[1];
}
