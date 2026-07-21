#include<stdio.h>
int main()
{
	int n,a[111111],t=1,i,c=0,f=0;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n;i++)
		if(a[i]==2)
			f=1;
	if(f==0){
		puts("-1");
		return 0;
	}
	while(n>=0){
		t=a[t-1];
		c++;
		if(t==2){
			printf("%d",c);
			return 0;
		}
		n--;
	}
	puts("-1");
	return 0;
}
