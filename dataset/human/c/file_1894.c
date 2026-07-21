#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  int N,a[25],b[25],c[25],i,count;
  char str[1000],*p;
  
  fgets(str,sizeof(str),stdin);
  N=atoi(str);
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  a[1]=atoi(p);
  for(i=2;i<N+1;i++){
    p=strtok(NULL," \n");
  	a[i]=atoi(p);
  }
  
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  b[1]=atoi(p);
  for(i=2;i<N+1;i++){
    p=strtok(NULL," \n");
  	b[i]=atoi(p);
  }
  
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  c[1]=atoi(p);
  for(i=2;i<N;i++){
    p=strtok(NULL," \n");
  	c[i]=atoi(p);
  }
  
  
  for(i=1,count=0;i<N+1;i++){
    count+=b[a[i]];
    if(a[i]>1 && a[i]-1==a[i-1]){
      count+=c[a[i-1]];
    }
  }
    
  printf("%d\n",count);
  
 return 0; 
}
