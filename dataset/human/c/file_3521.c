#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

int main(void)
{
    ll n, k, count, m;
    int i, ls, j, lc = 0;
    int pos[200002];
    int fl[200002] = {0};

    scanf("%lld %lld", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pos[i]);
        fl[i] = 1;
    }

    i = 0;
    count = 0;
    while (fl[i] != 0)
    {
        fl[i] = 0;
        i = pos[i] - 1;
        count++;
        if (count == k)
        {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    //printf("%d %lld\n", i, count); //一度訪れた街に戻るまでの回数
    ls = 0;
    if (i != 0)
    {
        while (pos[ls] != i + 1) //手前の町まで移動
        {
            ls = pos[ls] - 1;
            lc++;
        }
        ls = pos[ls] - 1; //ループの頭の町に移動
        lc++;
    }
    //printf("%d %d\n", ls, lc);
    i = 0;
    m = (k - lc) % (count - lc);
    for (; i < m; i++)
    {
        ls = pos[ls] - 1;
    }
    printf("%d\n", ls + 1);
    return 0;
}
