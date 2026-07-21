#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int A,B,K;
	scanf("%d%d%d",&A,&B,&K);
	int cnt=A+1,i;
	for(i=0;i<K;i++){
		do{
			cnt--;
		}while(A%cnt!=0||B%cnt!=0);
	}
	printf("%d",cnt);
	puts("");
	return 0;
}
