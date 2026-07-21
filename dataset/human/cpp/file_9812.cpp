#include <iostream>
#include <string>
using namespace std;


int main()
{
	int mod = 1e9 + 7;
	int n;
	string s;
	cin >> n;
	cin >> s;
	int a[26] = {};
	for (int i = 0; i < n; i++)
	{
		a[s[i] - 'a']++;

	}
	long long ans = 1;
	for (int i = 0; i < 26; i++)
	{
		ans *= (a[i] + 1);
		ans %= mod;
	}
	cout << ans - 1<< endl;

}
