#include <stdio.h>

int main(){

  int N,minv,maxv=0,i,j;

  scanf("%d",&N);
  
  int R[N];

  for(i=0;i<N;i++){
    scanf("%d",&R[i]);
  }
  
  minv = R[0];

  maxv = R[1] - R[0];

  for(j=1;j<=N-1;j++){
    if(maxv < R[j] - minv){
      maxv = R[j] - minv;
    }
    else{
      maxv = maxv;
    }

    if(minv < R[j]){
      minv = minv;
    }
    else{
      minv = R[j];
    }
    
    
  }

  printf("%d\n",maxv);

  return 0;
}
