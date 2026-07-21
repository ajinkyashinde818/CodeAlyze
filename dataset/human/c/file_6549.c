#include <stdio.h>

int main(){

  int n,i,max,min;

  scanf("%d",&n);

  int R[n];

  for(i = 0; i<n ; i++){
    scanf("%d",&R[i]);
  }
  
  min = R[0];
  max = R[1] - R[0];
  
  for(i=1 ; i<n; i++){
    if(max > R[i] - min) max = max;
    else if(max < R[i] - min) max = R[i]-min;

    if(min < R[i]) min = min;
    else if(min > R[i]) min = R[i];
  }

  printf("%d\n",max);

  return 0;

}
