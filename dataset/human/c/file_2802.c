#include<stdio.h>
int main(void)
{
	int k,s,i,j,c,z;
	scanf("%d%d",&k,&s);
	c=0;
	for(i=0;i<=k;i++){
		for(j=0;j<=k;j++){
			z=s-i-j;
			if(z<=k&&z>=0) c++;
		}		
	}
	printf("%d\n",c);
	return 0;
}
