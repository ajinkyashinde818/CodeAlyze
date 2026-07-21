#include<stdio.h>

#define RMAX 1000000
#define Max 200000
#define Min 2

int main(){
  int n,i;
  int R[RMAX];
  
  scanf("%d",&n);
  if(n>=Min && n<=Max)
    for(i=0; i<n; ++i){
      scanf("%d",&R[i]);
    }

  int min = R[0], max = R[1]-R[0];

  for(i=1; i<n; ++i){
    max = max < R[i] - min ? R[i] - min : max;
    min = min > R[i] ? R[i] : min;
  }

  printf("%d\n",max);
 
  return 0;
}
