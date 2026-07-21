#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

int n, m;
char a[N][N], b[N][N];

bool check(int r, int c)
{
    for(int i = 1; i <= m; i++)
        for(int  j = 1; j <= m; j++)
            if(a[i + r - 1][j + c - 1] != b[i][j])
                return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for(int i = 1; i <= m; i++) scanf("%s", b[i] + 1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(check(i, j))
            {
                puts("Yes");
                return 0;
            }

    puts("No");

    return 0;
}
