#include<stdio.h>
int main()
{
	int n,d,x,a[111],c=0,z=0,t=0,i,j=1;

	scanf("%d%d%d",&n,&d,&x);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	i=0;
	while(i<n){
		while(j*a[i]+1<=d){
			z++;
			j++;
		}
		c+=z+1;
		z=0;
		j=1;
		t=0;
		i++;
	}
	printf("%d",x+c);
	return 0;
}
