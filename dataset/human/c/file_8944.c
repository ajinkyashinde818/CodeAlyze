#include<stdio.h>
int main(void)
{
	int n,m,c;
	scanf("%d",&n);
	while(n!=0){
		c=0; m=n;
		while(m!=1){
			if(m%2==0) m=m/2;
			else m=m*3+1; c++;
		}
		printf("%d\n",c);
		scanf("%d",&n);
	}
	return 0;
}
