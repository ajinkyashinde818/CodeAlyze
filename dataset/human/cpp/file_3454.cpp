#include <iostream>
#include <cmath>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int cnt=0;
	long long ans=0;
	int mn=2e9;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		cnt^=(a[i]<0);
		ans+=abs(a[i]);
		mn=min(mn,abs(a[i]));
	}
	cout << ans-cnt*2*mn;
	return 0;
}
