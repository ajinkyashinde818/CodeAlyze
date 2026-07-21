#include <stdio.h>
 
int main (void){
  int n,d,x,a;
  int i;
  int eaten;
  
  scanf("%d",&n);
  scanf("%d %d",&d,&x);
  
  for( i=0, eaten=0, d--; i<n; i++){
    scanf("%d",&a);
    eaten = d / a;
    
    x += eaten+1;
  }
  
  printf("%d",x);
  
  return 0;
}
