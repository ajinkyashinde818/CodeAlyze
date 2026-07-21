#include <stdio.h>
int main(void){
int K,N,max,min;
int i=0;
  scanf("%d",&K);
  scanf("%d",&N);
 int d[N];
  for(i;i<N;i++)
   scanf("%d",&d[i]);
  max=d[0]+(K-d[N-1]);
  for(i=1;i<N;i++){
  if(max<d[i]-d[i-1])
    max=d[i]-d[i-1];}
  min=K-max;
  printf("%d",min);
  return 0;
}
