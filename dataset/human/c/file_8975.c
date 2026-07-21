#include<stdio.h>
int main(void)
{
	int n,cnt,x;
	scanf("%d",&n);
	while(n!=0) {
		x=n;
		cnt=0;
		while(x!=1) {
			if((x%2)!=0) {
				x=x*3+1;
				cnt=cnt+1;
			}
			else {
				x=x/2;
			cnt=cnt+1;
			}
		}
		printf("%d\n",cnt);
	scanf("%d",&n);
	}
	return 0;
}
