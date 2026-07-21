#include <stdio.h>
 
int main(void)
{
  
    int n,k,a={0},i; 
      
    scanf("%d%d",&n,&k);
   
    int h[n+1];
  
    for(i=0;i<n;i++) scanf("%d",&h[i]);
        
    for(i=0;i<n;i++){
        if(h[i]>=k) a=a+1;
    }
  
    printf("%d",a);
  
    return 0;
}
