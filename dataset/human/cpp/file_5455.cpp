#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll; 
int main(void)
{
	ll n,r;
	scanf("%lld%lld",&n,&r);
	if(10-n<0)
	{
		printf("%lld",r);
	}
	else
	{
		printf("%lld",r+100*(10-n));
	}
}
