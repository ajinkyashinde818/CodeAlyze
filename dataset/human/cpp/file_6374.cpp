#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin>>n>>s;
	if (s.at(0)=='W')
	{
		cout<<"0\n";
		return 0;
	}
	string memo="A";
	for (int i = 1; i < 2*n; ++i)
	{
		if (s.at(i-1)==s.at(i))
		{
			if (memo.at(i-1)=='A')
			{
				memo+="B";
			}
			else
			{
				memo+="A";
			}
		}
		else
		{
			if (memo.at(i-1)=='A')
			{
				memo+="A";
			}
			else
			{
				memo+="B";
			}
		}
	}
	long long ans=1LL,cnt=0LL;
	for (int i = 0; i < 2*n; ++i)
	{
		if (memo.at(i)=='A')
		{
			++cnt;
		}
		else
		{
			ans*=cnt;
			ans%=mod;
			--cnt;
		}
	}
	if (cnt>0LL)
	{
		cout<<"0\n";
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			ans*=(long long)i;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
