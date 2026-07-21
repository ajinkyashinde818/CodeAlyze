#include <stdio.h>

int ok_list[100010];

int main(void) {
	int n,i;
	int a,b;
	int max;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d%d",&a,&b);
		ok_list[a]++;
		ok_list[b+1]--;
	}
	for(i=1;i<100010;i++)ok_list[i]+=ok_list[i-1];
	max=1;
	for(i=1;i<100010;i++) {
		if(ok_list[i]>=i-1)max=i;
	}
	printf("%d\n",max-1);
	return 0;
}
