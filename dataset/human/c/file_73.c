#include<stdio.h>
 
int main(){
	int A,B,C,N;
	int count = 0;
  	int i,j;
	scanf("%d %d %d %d",&A,&B,&C,&N);
	
  	for(i=0;i<((int)(N/A)+1);i++){
      if((N-i*A)<0) continue;
    	for(j=0;j<((int)(N/B)+1);j++){
          	if((N-i*A-j*B)<0) continue;
    		if(0==((N-i*A-j*B)%C)) count = count+1;
        }
    }
    printf("%d\n",count);
	return 0;
}
