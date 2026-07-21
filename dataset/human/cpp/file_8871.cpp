#include<cstdio>
using namespace std;
char a[55][55];
char b[55][55];
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    char c;
    scanf("%c",&c);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%c",&a[i][j]);
        }
        scanf("%c",&c);
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%c",&b[i][j]);
        }
        scanf("%c",&c);
    }
    for(int x = 1; x <= n-m+1; x++)
    {
        for(int y = 1; y <= n-m+1; y++)
        {
            bool ok = true;
            for(int i = 1; i <= m; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    if(b[i][j] != a[x+ i - 1][y + j - 1])
                    {
                        ok = false;
                    }
                }
            }
            if(ok == true)
            {
                printf("Yes");
                return 0;
            }
        }
        
    }
    printf("No");
}
