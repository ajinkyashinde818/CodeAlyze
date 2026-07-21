#include <stdio.h>
int n, m, x, c[12]={}, a[12][12]={}, i, j, k, l, o, p, q, r, s, t, u, v, y, z[12], b, d = 1e9;
int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                for (l = 0; l < 2; l++)
                {
                    for (o = 0; o < 2; o++)
                    {
                        for (p = 0; p < 2; p++)
                        {
                            for (q = 0; q < 2; q++)
                            {
                                for (r = 0; r < 2; r++)
                                {
                                    for (s = 0; s < 2; s++)
                                    {
                                        for (t = 0; t < 2; t++)
                                        {
                                            for (u = 0; u < 2; u++)
                                            {
                                                for (v = 0; v < 2; v++)
                                                {
                                                    y=i*c[0]+j*c[1]+k*c[2]+l*c[3]+o*c[4]+p*c[5]+q*c[6]+r*c[7]+s*c[8]+t*c[9]+u*c[10]+v*c[11];
                                                    for(b=0;b<m;b++){
                                                        z[b]=i*a[0][b]+j*a[1][b]+k*a[2][b]+l*a[3][b]+o*a[4][b]+p*a[5][b]+q*a[6][b]+r*a[7][b]+s*a[8][b]+t*a[9][b]+u*a[10][b]+v*a[11][b];
                                                        if(z[b]<x)break;
                                                    }
                                                    if(b==m&&y<d)d=y;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(d==(int)1e9)puts("-1");
    else printf("%d",d);
    return 0;
}
