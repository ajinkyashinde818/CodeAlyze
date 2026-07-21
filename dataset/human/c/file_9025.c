#include<stdio.h>

int main(void){
	int n;
	int k;
	int h[100000];
	int i;
	int c;

	scanf("%d %d",&n,&k);
	c = 0;

	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
		if(h[i] >= k){
			c++;
		}
	}

	printf("%d\n",c);



		

	return 0;
}
