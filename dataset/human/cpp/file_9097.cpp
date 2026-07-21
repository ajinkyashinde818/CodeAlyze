#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char a[51][51], b[51][51];
    for(int i = 0; i < n; i++)scanf("%s", a[i]);
    for(int i = 0; i < m; i++)scanf("%s", b[i]);
    int i, j, ii, jj;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == b[0][0] && n-i >= m && n-j >= m)
            {
                for(ii = 0; ii < m; ii++)
                {
                    for(jj = 0; jj < m; jj++)
                    {
                        if(a[i+ii][j+jj] != b[ii][jj])break;
                    }
                    if(jj != m)break;
                }
                if(ii == m)
                {
                    printf("Yes");
                    return 0;
                }
            }
        }
    }
    printf("No");
    return 0;
}
