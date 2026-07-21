#include <stdio.h>
int main(void)
{
	int p,k,n,a,b,c;
	scanf("%d",&n);
	for(a=1;a<=n;a++){
		scanf("%d %d",&k,&p);
		b=k%p;
		if(b==0){
			printf("%d\n",p);
		}
		else{
			printf("%d\n",b);
		}
	}
	return 0;
}
