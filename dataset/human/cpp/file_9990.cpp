#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxl = 26;

int n;
int freq[Maxl];

int main()
{
    scanf("%d", &n);
    string s; cin >> s;
    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;
    int res = 1;
    for (int i = 0; i < Maxl; i++)
        res = ll(res) * (freq[i] + 1) % mod;
    res = (res - 1 + mod) % mod;
    printf("%d\n", res);
    return 0;
}
