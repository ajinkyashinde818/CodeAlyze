#include<stdio.h>

int main(){

  int R[200000];
  int n,i,j,minv;
  int v = 0,maxv = 0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  
  minv = R[0];
  maxv = R[1]-R[0];
  
  for(j=1;j<n;j++){
    v = R[j]-minv;
    if(v>maxv)maxv=v;
    if(minv>R[j])minv=R[j];
  }
      
  printf("%d\n",maxv);
  
  return 0;
}
