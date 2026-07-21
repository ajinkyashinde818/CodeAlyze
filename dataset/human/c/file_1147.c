#include <stdio.h>

int *bubbleSort(int *N, int len)
{
    int i, j, temp;

    for (i = 0; i < len; i++)
    {
        for (j = len - 1; j > i; j--)
        {
            if (N[j] < N[j - 1])
            {
                temp = N[j];
                N[j] = N[j - 1];
                N[j - 1] = temp;
            }
        }
    }

    return N;
}

int *reverse(int *N, int len)
{
int temp;

for(int i=0;i<len/2;i++){
    temp=N[i];
    N[i]=N[len-i-1];
    N[len-i-1]=temp;
}

    return N;
}

int main(void)
{
    int s[105], t[105];
    int ls, lt, len;
    int i, temp;

    ls = 0;
    while ((temp = getchar()) != '\n')
    {   //s
        //printf("%c",temp);
        s[ls] = temp;
        ls++;
    }
    bubbleSort(s, ls);
    //printf("%d\n",ls);

    lt = 0;
    while ((temp = getchar()) != '\n')
    {   //t
        // printf("%c",temp);
        t[lt] = temp;
        lt++;
    }
    bubbleSort(t, lt);
    reverse(t,lt);
    //printf("%d\n",lt);
    //printf("%d %d\n",s[0],s[1]);

    if (ls > lt)
        len = lt;
    else
        len = ls;
    //printf("%d %d %d\n",ls,lt,len);
    for (i = 0; i < len; i++)
    {
        //printf("%d %d\n", s[i], t[i]);
        if (s[i] < t[i])
        {
            printf("Yes");
            return (0);
        }
        else if (s[i] > t[i])
        {
            printf("No");
            return (0);
        }
    }
    if (ls < lt)
        printf("Yes");
    else
        printf("No");

    return (0);
}
