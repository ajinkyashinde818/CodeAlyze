#include <stdio.h>

int main(void) {
  int min = 999999999,max = -999999999,n,i,j,r,a,b;
  scanf("%d",&n);
  if(n == 2){
    scanf("%d%d",&a,&b);
    printf("%d\n",b - a);
  }
  else{
    for(i = 0; i < n; i++){
      scanf("%d",&r);
      if(i != 0 && max < r - min)max = r - min;
      if(min > r)min = r;
      //printf("max = %d,min = %d\n",max,min);
    }
    printf("%d\n",max);
  }
  return 0;
}
