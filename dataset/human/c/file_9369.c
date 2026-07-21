#include<stdio.h>
int main()
{
	int n,day,x,i,y,k=0;
	scanf("%d%d%d",&n,&day,&x);
	for(i=0;i<n;i++){
		scanf("%d",&y);
		k+=(day-1)/y+1;
	}
	printf("%d",k+x);
	 return 0;


}
