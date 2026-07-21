#include <stdio.h>
#define N 200000


main(){


  int i,n,rieki,money;
  int a[N];
  
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    
    scanf("%d",&a[i]);
    
    if(rieki < a[i]-money){
      rieki = a[i] - money;
    }
    
    if(money > a[i]){
       money = a[i];
       }
    
    
    if(i == 0){
      money = a[i];
      rieki = -a[i];
    }
    
  }
  
  printf("%d\n",rieki);
  
  
  
  return 0;
}
