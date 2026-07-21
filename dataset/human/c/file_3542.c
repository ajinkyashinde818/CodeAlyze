#include<stdio.h>
int main(void)
{
	int n,p[100],i,j,c,cnt;
	c=0;
	cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<=n;i++){
		for(j=0;j<n;j++){
			if(i<=p[j]) c++;
		}
		if(i<=c) cnt=i;
		c=0;
	}
	printf("%d\n",cnt);
	return 0;
}
