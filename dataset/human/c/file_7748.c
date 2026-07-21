#include<stdio.h>
int main(void)
{
	int a, n, k, p, i;
	scanf("%d",&a);
	for(i = 0;i < a ;i++){
	scanf("%d %d",&k,&p);
	n = k % p;
	if(n == 0){
		printf("%d\n",p);
	}
	else if (p >= k){
		printf("%d\n",k);
	}
	else if (k >= p){
		printf("%d\n",n);
	}
		}
	return 0;
}
