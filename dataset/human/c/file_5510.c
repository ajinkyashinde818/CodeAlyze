#include <stdio.h>
#define MAX 300000
int main(void){
	unsigned short a[MAX] = {0};
	int sum[MAX];
	int csum = 0;
	int c,i,j,n;
	c = 0;
	for(i = 2; i < MAX; i++){
		if(a[i] == 0){
			c++;
			csum += i;
			sum[c] = csum;
			for(j = i; j < MAX; j += i){
				a[j] = 1;
			}
		}
	} 
	while(1){
		scanf("%d",&n);
		if(n == 0){break;}
		printf("%d\n",sum[n]);
	}


	return 0;
}
