#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,m=0,i=0,sum=0;
  scanf("%d",&n);
  int a[n], b[n],c[n-1];
  while(m!=n){
    scanf("%d",&a[i++]);    
    m++;
  }
  
  i=0;m=0;
  while(m!=n){
    scanf("%d",&b[i++]);
    m++;
  }

   
  i=0;m=0;
  while(m!=n-1){
    scanf("%d",&c[i++]);
    m++;
  }
  
  i=0;m=0;
  int next = 0;
  while(i!=n){
    if(next == a[i]){
      sum+=c[a[i-1]-1];
    }
    sum += b[a[i++]-1];
    next = a[i-1]+1;
  }
  printf("%d\n",sum);
  
  return 0;
}
