#include <stdio.h>

int D;
long long G;
int p[20];
int c[20];

int S[20];
int pcS[20];

int min = 99999;
bool gc[20];

void Si(int i, long long score, int num)
{
    if (i > D)
    {
        if (score < G)
        {
            for (int j = D; j > 0; j--)
            {
                if (!gc[j] && score + S[j] >= G)
                {
                    num += (G - score - 1) / (j * 100) + 1;
                    if (num < min)
                        min = num;
                }
            }
        }
        else
        {
            if (num < min)
                min = num;
        }
        return;
    }

    gc[i] = false;
    Si(i + 1, score, num);
    gc[i] = true;
    Si(i + 1, score + pcS[i], num + p[i]);
}

int main()
{
    scanf("%d", &D);
    scanf("%lld", &G);
    for (int i = 1; i <= D; i++)
    {
        int P, C;
        scanf("%d%d", &P, &C);
        S[i] = 100 * i * (P - 1);
        pcS[i] = P * 100 * i + C;
        p[i] = P;
        c[i] = C;
    }
    Si(1, 0, 0);

    printf("%d", min);

    return 0;
}
