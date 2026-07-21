#include<stdio.h>
int main(void)
{
	int n;
	int i;
	int k,p;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		k=k%p;
		if(k!=0){
			printf("%d\n",k);
		}
		else {
			printf("%d\n",p);
		}
	}
	return 0;
}
