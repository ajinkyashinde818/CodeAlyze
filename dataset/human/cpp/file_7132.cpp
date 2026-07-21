#include<iostream>
#include<algorithm>
typedef long long lint;
using namespace std;

int main()
{
	int N;
	lint a[200010]={};
	lint sum=0;
	lint ans=2e9+10;
	
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	for(int i=1;i<N;i++)
	{
		a[i]+=a[i-1];
		ans=min(ans,abs(a[i]-(sum-a[i])));
	}
	cout << ans << endl;
	return 0;
}
