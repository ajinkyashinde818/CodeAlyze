#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
ll mod = 1000000007, a[26], ans = 1;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        a[(int) (s[i] - 'a')]++;
    for (int i = 0; i < 26; i++)
        ans = (ans * (a[i] + 1)) % mod;
    cout << ans - 1 << endl;
    return 0;
}
