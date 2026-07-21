#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long int

int n,m,x;
int c[14];
int a[14][14];

int main(){

  scanf("%d%d%d",&n,&m,&x);
  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
    for(int j=0;j<m;j++){
      scanf("%d",&a[i][j]);}}
  
  ll mincost=2000000;

  for(int i=1;i<4096;i++){
    int t=i;
    ll tmpcost=0;
    ll tmp[14]={};
    for(int j=0;j<n;j++){
      if(t%2==1){
	for(int l=0;l<m;l++){
	  tmp[l]+=a[j][l];}
	tmpcost+=c[j];}
      t/=2;}
    int check=1;
    for(int j=0;j<m;j++){
      if(tmp[j]<x){
	check=0; break;}}
    if(check==1 && mincost>tmpcost){
      mincost=tmpcost;}
  }
  
  if(mincost==2000000){
    mincost=-1;}

  printf("%lld\n",mincost);

  
  return 0;
}
