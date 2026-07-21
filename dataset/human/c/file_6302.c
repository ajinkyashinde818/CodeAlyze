#include <stdio.h>
#define SIZE 200000

int max(int x,int y){
  if(x>y) return x;
  else return y;
}

int min(int x,int y){
  if(x>y) return y;
  else return x;
}

int main(){

  int R[SIZE],n;
  int minv,maxv,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  maxv=-2000000000;
  minv=R[0];

  for(i=1;i<n;i++){
    maxv=max(maxv,R[i]-minv);
    minv=min(minv,R[i]);
}

  printf("%d\n",maxv);

  return 0;
}
