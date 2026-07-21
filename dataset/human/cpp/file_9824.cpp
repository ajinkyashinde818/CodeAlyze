#include <bits/stdc++.h>
using namespace std;

string s;
const int M = 1000000007;
map<char, int> m;
int n;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }
    map<char, int>::iterator p;
    long long int ans = 1;
    for (p = m.begin(); p != m.end(); p++)
    {
        ans *= p->second + 1;
        ans %= M;
    }
    cout << ans - 1 << endl;
    return 0;
}
