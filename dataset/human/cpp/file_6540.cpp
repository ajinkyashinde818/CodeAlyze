#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int mult(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = 2e5 + 1;

char s[N];

int main()
{
    int n;
    scanf("%d %s", &n, s);
    vector<int> zero, one;
    for (int i = 0; i < 2 * n; ++i)
    {
        if ((s[i] == 'W') ^ (i & 1))
            one.push_back(i);
        else
            zero.push_back(i);
    }
    
    if ((int)one.size() != n)
    {
        printf("0");
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < n; ++i)
    {
        static int pos = 0;
        while(pos < n && one[i] > zero[pos]) ++pos;
        ans = mult(ans, pos - i);
        ans = mult(ans, i + 1);
    }

    printf("%d", ans);
}
