#include<iostream>

using namespace std;

const int N(1e5 + 9);

int n, m;
long long ans;
long long a[N], f[N][2];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f[1][0] = a[1];
	f[1][1] = -a[1];
	for (int i=2;i<=n;i++)
	{
		f[i][0] = max(f[i - 1][0] + a[i], f[i - 1][1] - a[i]);
		f[i][1] = max(f[i - 1][0] - a[i], f[i - 1][1] + a[i]);
	}
	cout<<f[n][0]<<endl;
	return 0;
}
