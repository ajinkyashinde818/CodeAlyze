#include <iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
char mp1[55][55], mp2[55][55];
int main()
{
    int n, m, i, j, o, p;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; ++i) scanf("%s", mp1[i]);
    for(i = 0; i < m; ++i) scanf("%s", mp2[i]);
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(i + m <= n && j + m <= n)
            {
                for(o = 0; o < m; ++o)
                {
                    for(p = 0; p < m; ++p)
                    {
                        if(mp1[i + o][j + p] != mp2[o][p])
                        {
                            goto c;
                        }
                    }
                }
                printf("Yes\n");
                goto d;
                c:;
            }
        }
    }
    printf("No\n");
    d:;
    return 0;
}
