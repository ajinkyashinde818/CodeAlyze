#include<stdio.h>

main(){
  
  int n,i,min,t,max,t0;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
   
    scanf("%d",&t);
   
    if(i==0) t0 = t;

    if(i == 1) max = t - t0;
    else if (max < t - min) max = t - min;

 
    if(i == 0) min = t;
    else if (min > t) min = t;

    
  }
  
  printf("%d\n",max);

    return 0;
    
}
