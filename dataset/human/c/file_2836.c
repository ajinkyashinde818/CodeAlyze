#include<stdio.h>
int main()
{
	int k,s,x,y,z,c=0;

	scanf("%d%d",&k,&s);

	for(x=0;x<=k;x++)
		for(y=0;y<=k;y++){
			z=s-x-y;
			if(0<=z&&z<=k)
				c++;
		}
	printf("%d",c);
	return 0;
}
