#include<stdio.h>
int main(void)
{
	int n,cnt,i;
	scanf("%d",&n);
	while(n!=0){
		cnt=0;
		while(n!=1){
			if(n%2==0){
				n=n/2;
				cnt++;
			}
			else if(n%2!=0){
				n=(n*3)+1;
				cnt++;
			}
		}
	printf("%d\n",cnt);
	scanf("%d",&n);
	}
	return 0;
}
