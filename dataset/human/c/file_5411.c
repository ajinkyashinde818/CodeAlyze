#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//typedef long long ll;
int main(void)
{
  int n,m,x,ans=0;
  scanf("%d%d%d",&n,&m,&x);
  int c[n],a[n][m],tmp[m];
  for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
    for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
  }
  for(int i=0;i<m;i++) tmp[i]=0;
  int i=0,flag=0,tmp1=0,tmp2=0;
  //i=i>>3;
  while(((i>>n)&1)!=1){
    for(int j=0;j<n;j++){
      if(((i>>j)&1)==1){
        for(int u=0;u<m;u++){
          tmp[u]+=a[j][u];
        }
        tmp1+=c[j];
      }
    }
    for(int j=0;j<m;j++){
      if(tmp[j]<x) flag=1;
      tmp[j]=0;
    }
    if(flag==0)
      if((tmp2>tmp1)||(tmp2==0)) tmp2=tmp1;
    tmp1=0;
    flag=0;
    i++;
  }
  if(tmp2>0) printf("%d",tmp2); 
  else printf("-1"); 
  return 0;
}
