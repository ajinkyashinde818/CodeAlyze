#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  
  int N,D,X,A[105],eat,i,j;
  char str[100],*p;
  
  fgets(str,sizeof(str),stdin);
  N=atoi(str);
  fgets(str,sizeof(str),stdin);
  p=strtok(str," \n");
  D=atoi(p);
  p=strtok(NULL," \n");
  X=atoi(p);
  
  for(i=0;i<N;i++){
    fgets(str,sizeof(str),stdin);
    A[i]=atoi(str);
  }
  for(i=0,eat=0;i<N;i++){
    for(j=0;j*A[i]<D;j++){
     eat++; 
    }
  }
  
  printf("%d\n",eat+X);
  
 return 0; 
}
