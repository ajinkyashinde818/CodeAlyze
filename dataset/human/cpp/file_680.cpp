#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	int a[3];
	cin >> a[0] >> a[1] >> a[2] >> n;
	int cnt = 0;
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=n;j++)
		{
			if(n-a[0]*i-a[1]*j<0)continue;
			if((n-a[0]*i-a[1]*j)%a[2]==0)
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
