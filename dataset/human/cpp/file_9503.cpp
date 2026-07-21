#include <cstdio>

using namespace std;
int n,m,i,j,k,h;
char x,s[54][54],s1[54][54];
bool ok,ok1;
int main()
{
    scanf ("%d %d", &n, &m);
    for (i=0;i<=(n-1);i++)
    {
        scanf ("%c", &x);
        for (j=0;j<=(n-1);j++)
            scanf ("%c", &s[i][j]);
    }
    for (i=0;i<=(m-1);i++)
    {
        scanf ("%c", &x);
        for (j=0;j<=(m-1);j++)
            scanf ("%c", &s1[i][j]);
    }
    ok1=false;
    for (i=0;(i<=(n-m)) && (ok1==false);i++)
        for (j=0;(j<=(n-m)) && (ok1==false);j++)
        {
            ok=true;
            for (k=0;(k<=(m-1)) && (ok==true);k++)
                for (h=0;h<=(m-1);h++)
                {
                    if (s[i+k][j+h]!=s1[k][h])
                    {
                        ok=false;
                        break;
                    }
                }
            if (ok==true)
                ok1=true;
        }
    if (ok1==true)
        printf ("Yes\n");
    else
        printf ("No\n");
    return 0;
}
