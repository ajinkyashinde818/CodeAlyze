#include<stdio.h>

int main(){
  int i,j,n,r[200000],maxv=-1000000000,minv;

 scanf("%d",&n);
 
  for(i=0;i<n;i++) scanf("%d",&r[i]);
  minv=r[0];
  for(j=1;j<n;j++){
    if(maxv<r[j]-minv)maxv=r[j]-minv;
 if(minv>r[j])minv=r[j];
}
  printf("%d\n",maxv);

  return 0;
}
