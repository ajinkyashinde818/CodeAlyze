#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
ll n, ans = 1, c[150];
string s;
int main()
{
	ll i;
	cin >> n >> s;
	for (i = 0; i < n; i++) c[s[i]]++;
	for (i = 'a'; i <= 'z'; i++) ans = ans * (c[i] + 1) % M;
    cout << ans - 1 << endl;
    return 0;
}
