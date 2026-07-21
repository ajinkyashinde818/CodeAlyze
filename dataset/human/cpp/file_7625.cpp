#include<iostream>
#include<cctype>
#include<vector>
#include <ctype.h>
#include<algorithm>
#include<queue>
#include<string>
#include <math.h>
#include <iomanip>
using namespace std;
long long n, s[200000], ans,a[200000],t=0;
int main() {
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> s[i];
		t += s[i];
		a[i] = t;
	}
	ans = abs(a[n - 1] - 2 * a[0]);
	for (long long  i = 0; i < n-1; i++)
	{
		ans=min(abs(a[n - 1] - 2 * a[i]), ans);
	}
	cout << ans << endl;
	return 0;
}
