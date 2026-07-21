#include <stdio.h>
int main() 
{
  int maxv,minv,num,i,R[200000];
  scanf("%d",&num);

  for(i=0; i<num; i++){
    scanf("%d",&R[i]);
  }

  minv = R[0];
  maxv = R[1] - R[0];

  for(i=1; i<num; i++){
    if(maxv < R[i] - minv) maxv = R[i] - minv;
    if(minv > R[i]) minv = R[i];
  }

  printf("%d\n",maxv);

  return 0;

}
