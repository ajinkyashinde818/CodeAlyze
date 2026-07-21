#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int N,i;
  long a[100005],sum,count,zero,min;
  char str[2000005],*p;
  
  fgets(str,sizeof(str),stdin);
  N=atoi(str);
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  a[0]=atol(p);
  for(i=1;i<N;i++){
    p=strtok(NULL," \n");
    a[i]=atol(p);
  }
  
  for(i=0,count=0,zero=0;i<N;i++){
    if(a[i]<0){
      count++;
    }
    if(a[i]==0){
      zero++;
    }
  }
  for(i=0;i<N;i++){
      sum+=labs(a[i]);
    }
  
  if(zero!=0 || count%2==0){
    printf("%ld\n",sum);
    return 0;
  }
  
  if(count%2==1){
    for(i=0,min=labs(a[0]);i<N;i++){
      if(labs(a[i])<min){
        min=labs(a[i]);
      }
    }
    printf("%ld\n",sum-2*labs(min));
    return 0;
    
  }

  
}
