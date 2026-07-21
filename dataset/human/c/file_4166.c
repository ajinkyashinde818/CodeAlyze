#include<stdio.h>
int main()
{
	int a,b,k,r,s[100],c=0,i;

	scanf("%d%d%d",&a,&b,&k);

	if(a<b){
		a+=b;
		b=a-b;
		a=a-b;
	}
	r=a%b;
	for(i=1;i<=b;i++)
		if((a%i==0)&&(b%i==0)){
			c++;
			s[c-1]=i;
		}
	printf("%d",s[c-k]);
	return 0;
}
