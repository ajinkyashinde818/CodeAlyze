#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  char str[30];
  long int x,i,N,sum;
  
  fgets(str,sizeof(str),stdin);
  N=atol(str);
  
  if(N%2==1){
    printf("0");
  }else{
    N=N/2;
    sum=0;
    for(i=1;(long int)powl(5,i)<=N;i++){
      x=(long int)powl(5,i);
      sum+=N/x;
    }
    printf("%ld\n",sum);
  }
  return 0;
}
