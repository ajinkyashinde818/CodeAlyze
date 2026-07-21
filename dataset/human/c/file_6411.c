#include<stdio.h>

int main(){
  int j,n,maxv,minv;

  scanf("%d",&n);

  int R[n];

  for(j=0;j<n;j++){
    scanf("%d",&R[j]);
  }
  
  minv = R[0];
  maxv = R[1]-R[0];
  for(j=1;j<n;j++){
    if(maxv<R[j]-minv){
      maxv=R[j]-minv;
    }else{
      maxv=maxv;
    }
    if(minv>R[j]){
      minv=R[j];
    }else{
      minv=minv;
    }
  }
  printf("%d\n",maxv);
  return 0;
}
