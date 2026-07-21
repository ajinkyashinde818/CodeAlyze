#include<stdio.h>

int max(int a,int b){
  if(a>b) return a;
  return b;
}
int min(int a,int b){
  if(a<b) return a;
  return b;
}

int main(){
  int i,n,R[200000],maxv,minv;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&R[i]);
  maxv=-2000000000;
  minv=R[0];
  for(i=1;i<n;i++){
    maxv=max(maxv,R[i]-minv);
    minv=min(minv,R[i]);
  }
  printf("%d\n",maxv);
  return 0;
}
