#include<stdio.h>
int n,m,d[110];
int f(int l,int r){//printf("%d %d ",l,r);
  if(r-l<1)return l;
  int mid=(l+r)/2,c=1,i,s=0;
  for(i=0;i<n;i++){
    if(s+d[i]>mid){
      s=0;
      c++;
    }
    s+=d[i];
    if(mid<d[i]){
      c=1000;
      break;
    }
  }//printf("%d\n",c);
  return c>m?f(mid+1,r):f(l,mid);
}
int main(){
  int i;
  while(scanf("%d %d",&m,&n),m||n){
    for(i=0;i<n;i++)scanf("%d",&d[i]);
    printf("%d\n",f(0,1500000));
  }
  return 0;
}
