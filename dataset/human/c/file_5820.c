#include <stdio.h>

int main(){
  int maxv;
  int minv;
  int R[200000];
  int num;
  int i;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&R[i]);
  }

  maxv = R[1] - R[0];
  minv = R[0];

  for(i=1;i<num;i++){

    maxv = maxv > R[i] - minv ? maxv : R[i] - minv;

    minv = minv < R[i] ? minv : R[i];
  }

  printf("%d\n",maxv);

  return 0;
}
