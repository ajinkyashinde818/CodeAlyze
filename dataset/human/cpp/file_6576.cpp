#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int n;
char str[Maxn];
int res = 1;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    int cur = 0;
    for (int i = 0; i < 2 * n; i++)
        if (str[i] == 'W')
            if (cur % 2 == 0) { res = ll(res) * cur % mod; cur--; }
            else cur++;
        else if (str[i] == 'B')
            if (cur % 2 == 0) cur++;
            else { res = ll(res) * cur % mod; cur--; }
    if (cur != 0) res = 0;
    for (int i = 2; i <= n; i++)
        res = ll(res) * i % mod;
    printf("%d\n", res);
    return 0;
}
