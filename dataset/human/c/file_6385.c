#include<stdio.h>
#define MAX 200000

int main(){
  int R[MAX],i,n=0;
  int max = -2000000000;

  scanf("%d",&n);

  for(i = 0; i < n; i++ ) scanf("%d",&R[i]);

 int min = R[0];
  for(i = 1; i < n; i++ ){
    if(max < (R[i] - min)) max = (R[i] - min);
    if(min > R[i]) min = R[i];
  }

  printf("%d\n",max);

  return 0;
}
