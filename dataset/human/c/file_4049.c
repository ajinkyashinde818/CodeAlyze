#include <stdio.h>
 
int main(){
	int A,B,K;
  	int i,number,sum=0;
  	int wari[150]={0};
 
  
  if(scanf("%d %d %d", &A,&B,&K) < 3) {
    fprintf(stderr, "error: ill-formed fraction.\n");
}
  
  for(i=1;i<=110;i++){
  	if(A%i == 0 && B%i ==0) wari[i]=1;
    else;
   // printf("wari[%d]%d ",i,wari[i]);
  }
  
  
  for(i=110;i>0;i--){
  	sum+=wari[i];
    if(sum==K) break;
    else;
  }
  
  printf("%d",i);
  
  return 0;
}
