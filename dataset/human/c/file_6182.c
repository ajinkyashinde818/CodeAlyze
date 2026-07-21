#include<stdio.h>

int main(){
  int N,val[200000];
  int i,j;
  int maxv,minv,benefit;
  
  scanf("%d",&N);

  for(i=0;i<N;++i){
    scanf("%d",&val[i]);
  }

  maxv=val[1]-val[0];
  minv=val[0];

  for(i=1;i<N;++i){
    if(maxv<val[i]-minv) maxv=val[i]-minv;
    if(minv>val[i]) minv=val[i];
  }

  printf("%d\n",maxv);

  return 0;
}
