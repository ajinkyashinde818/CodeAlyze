#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<math.h>
#include<stack>
#include<assert.h>
using namespace std;
typedef long long ll;

const int max_n = 1e5 + 5;
 
 
int N;
ll C,ans,x[max_n],v[max_n],a[max_n],b[max_n];
ll aa[max_n], bb[max_n];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >>C;
	for (int i = 1; i <= N; i++)
		cin >> x[i] >> v[i];

	for (int i = 1; i <= N; i++)
	{
		a[i] = a[i - 1] + v[i];
		ans = max(ans, a[i]-x[i]);
		aa[i] = max(aa[i - 1], a[i] - 2 * x[i]);
	}
	for (int i = N; i > 0; i--)
	{
		b[i] = b[i + 1] + v[i];
		ans = max(ans, b[i]-(C-x[i]));
		bb[i] = max(bb[i + 1], b[i] - 2 * (C-x[i]));
	}

	for (int i = 1; i <= N; i++)
	{
		ans = max(ans, a[i] - x[i] + bb[i+1]);
		ans = max(ans, b[i] - (C - x[i]) + aa[i-1]);
	}
	cout << ans;
}
