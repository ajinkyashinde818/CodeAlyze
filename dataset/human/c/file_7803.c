#include<stdio.h>
int main()
{
	int n,k,p,i,stone;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		stone=k%p;
		if(stone==0)
		stone=p;
		printf("%d\n",stone);
	}	
	return 0;
}
