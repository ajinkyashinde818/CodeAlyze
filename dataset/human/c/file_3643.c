#include<stdio.h>
#include<string.h>
int main()
{long long t,m,n;
scanf("%lld%lld",&m,&n);
t=m*n;
while(m!=n)
if(m>n)
	m=m-n;
else if(m<n)
	n=n-m;
t=t/n;
printf("%lld",t);
}
