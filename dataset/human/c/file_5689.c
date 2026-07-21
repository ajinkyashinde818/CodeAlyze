#include<stdio.h>
#include<math.h>

int main(void){

  int MAX = 200000;
  int R[MAX],n;
  int maxv = -2000000000;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d", &R[i]);
  }
  int minv = R[0];
  for(i=1;i<n;i++){
    if(maxv<R[i]-minv) maxv = R[i]-minv;
    if(minv>R[i]) minv = R[i];
      } 
  printf("%d\n",maxv);
  //  printf("minv;%d\n", minv);                                                
  return 0;
}
