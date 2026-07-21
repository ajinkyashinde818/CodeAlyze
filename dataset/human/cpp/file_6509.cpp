#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

constexpr lint mod=1e9+7;

int main()
{
	int N;
	string S;

	cin >> N >> S;

	if(S[0]=='W')
	{
		cout << 0 << endl;
		return 0;
	}

	lint ans=1;
	lint sec=0;
	for(int i=0;i<S.size();i++)
	{
		if((S[i]=='W' && sec%2==0) || (S[i]=='B' && sec%2==1))
		{
			ans*=sec;
			ans%=mod;
			sec--;
		}
		else if((S[i]=='W' && sec%2==1) || (S[i]=='B' && sec%2==0))
		{
			sec++;
		}
	}
	if(sec!=0)ans=0;

	for(lint i=1;i<=N;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout << ans << endl;
	return 0;
}
