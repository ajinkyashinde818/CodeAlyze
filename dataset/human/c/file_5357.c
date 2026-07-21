#include<stdio.h>//高速化したい
#define rep(i,n)for(int i=0;i<(int)(n);i++)
int main(){
int n,m,x,c[12]={0},a[12][12]={0},y,z[12],b,d=2e9;
scanf("%d%d%d",&n,&m,&x);
rep(i,n){
scanf("%d",&c[i]);
rep(j,m){
scanf("%d",&a[i][j]);
}
}
rep(i,2){rep(j,2){rep(k,2){rep(l,2){rep(o,2){rep(p,2){rep(q,2){rep(r,2){rep(s,2){rep(t,2){rep(u,2){rep(v,2){
y=i*c[0]+j*c[1]+k*c[2]+l*c[3]+o*c[4]+p*c[5]+q*c[6]+r*c[7]+s*c[8]+t*c[9]+u*c[10]+v*c[11];
for(b=0;b<m;b++){
z[b]=i*a[0][b]+j*a[1][b]+k*a[2][b]+l*a[3][b]+o*a[4][b]+p*a[5][b]+q*a[6][b]+r*a[7][b]+s*a[8][b]+t*a[9][b]+u*a[10][b]+v*a[11][b];
if(z[b]<x)break;
}
if(b==m&&y<d)d = y;
}}}}}}}}}}}}
if(d==(int)2e9)puts("-1");
else printf("%d",d);
return 0;
}
