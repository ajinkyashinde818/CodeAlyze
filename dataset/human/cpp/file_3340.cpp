#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a;
	long long ans = 0;

	int num_minus = 0;	// 0 : マイナスが偶数個
	int minx = 1000000000;
	for( int i = 0; i < n; ++i )
	{
		cin >> a;
		if( a < 0 )
		{
			num_minus ^= 1;
			minx = min( -a, minx );
			ans -= a;
		}
		else
		{
			minx = min( a, minx );
			ans += a;
		}
	}
	if( num_minus )	// マイナスが奇数個
		ans -= 2*minx;

	cout << ans << endl;
	return 0;
}
