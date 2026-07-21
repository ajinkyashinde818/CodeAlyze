#include<stdio.h>
int main(void)
    {
    	int a,s,i,j,k,b;
    	scanf("%d",&a);
    	scanf("%d",&s);
    	b=0;
    	for(i=0;i<=a;i++){
    		for(j=0;j<=a;j++){
    			if(0<=s-i-j&&s-i-j<=a){ 
					b=b+1;
    	}
			}
		}
		
    	printf("%d\n",b);
    }
