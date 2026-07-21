#include<stdio.h>
int main()
{
	int n,k,h[100000];
	int i,c=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	for(i=0;i<n;i++){
		if(k<=h[i]){
			c++;
		}
	}
	printf("%d\n",c);
	return 0;
}
