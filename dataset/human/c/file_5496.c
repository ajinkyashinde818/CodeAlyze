#include <stdio.h>

int main(void) {
	int sosuu[10000];
	int i,j,k;
	int n;
	sosuu[0]=2;
	for(i=3,j=1;j<10000;i+=2) {
		for(k=0;k<j;k++) {
			if(i%sosuu[k]==0)break;
		}
		if(k>=j) {
			sosuu[j]=i;
			j++;
		}
	}
	for(i=1;i<10000;i++)sosuu[i]+=sosuu[i-1];
	while(1) {
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",sosuu[n-1]);
	}
	return 0;
}
