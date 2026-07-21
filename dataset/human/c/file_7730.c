#include <stdio.h>
int main (void){
	int k,p,n,a=0,b=0,c=0,d=0;
	scanf("%d",&n);
	for(a=1;a<=n;a++){
	scanf("%d %d",&k,&p);
		if(k%p==0){
			b=p;
			printf("%d\n",b);
		}
		else {
			c=k%p;
			printf("%d\n",c);
		}
	}
		
	return 0;
}
