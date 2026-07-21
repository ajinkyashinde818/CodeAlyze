#include<bits/stdc++.h>
using namespace std;

long long n,num,f,t,fh,th;

int main()
{
	scanf("%lld",&n);
	scanf("%lld",&num);
	f = num;
	t = -num;
	for ( long long i = 1 ; i < n ; i++ )
	{
		scanf("%lld",&num);
		fh = max(f+num,t-num);
		th = max(f-num,t+num);
		f = fh;
		t = th;
	}
	printf("%lld",f);
	printf("\n");
	return 0;
}
