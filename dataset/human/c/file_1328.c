#include<stdio.h>
#include<stdlib.h>
int asc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;
    int a, b;
    int s[200005], g[200005];
    int ns, ng;
    ns = ng = 0;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        if (a == 1)
        {
            s[ns] = b;
            ns++;
        }
        else if (b == n)
        {
            g[ng] = a;
            ng++;
        }
    }
    qsort(s, ns, sizeof(int), asc);
    qsort(g, ng, sizeof(int), asc);
    i = j = 0;
    while (s[i] != g[j] && i < ns && j < ng)
    {
        if (s[i] < g[j])i++;
        else j++;
    }
    if (s[i] == g[j])
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");
    return 0;
}
