#include <stdio.h>
#include <math.h>
int main(void){
    int a,n,c=0,i,j,f,r,min,max=-100000000;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
    	scanf("%d",&a);
    	if(i==1){
    		min=f;
    		max=a-min;
    	}
    	
    	if(min>f&&i!=0){
    		min=f;
    	}
    	if(max<a-min){
    		max=a-min;
    	}
    	f=a;
    	//printf("max=%d,min=%d\n",max,min);
	}
    printf("%d\n",max);
    
    return 0;
}
