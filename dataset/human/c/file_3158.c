#include <stdio.h>
int main(){
  long k,n,a0,a1,a2,a_all=0,a_max=0,i;
  
  scanf("%ld %ld",&k,&n);
  
  scanf("%ld",&a0);
  a_all+=a0;
  a1=a0;
  
  for(i=1;i<n;i++){
    scanf("%ld",&a2);
    if((a2-a1)>a_max){
      a_max=a2-a1;
    }
    a1=a2;
  }
  
  if((k-a2+a0)>a_max){
    a_max=k-a2+a0;
  }
  
  printf("%ld",k-a_max);
}
