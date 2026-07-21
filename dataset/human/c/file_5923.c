#include <stdio.h>

int main(){
    int h,i,j,n,min,max;
    max = -9999999999;
    
    scanf("%d",&n);
    
    scanf("%d",&h);
    min = h;
	
    for(j = 1;j < n;j++){
      scanf("%d",&i);
      
      if(max > i-min)
         max = max;
      else
         max = i-min;

      if(i > min)
         min = min;
      else 
         min = i;
    }

    printf("%d\n",max);

    return 0;
}
