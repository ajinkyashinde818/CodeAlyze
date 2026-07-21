#include<stdio.h>
#include<string.h>

int main()
{
    int n, a = 0;
    int a_array[21];
    int b_array[21];
    int c_array[21];

    scanf("%d", &n);

    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &a_array[i]);
    }

    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &b_array[i]);
    }

    for (int i = 1; i<n; i++)
    {
        scanf("%d", &c_array[i]);
    }

    for (int i = 1; i<=n; i++)
    {
        a += b_array[a_array[i]];

        if (i == n)
            break;

        if ((a_array[i] + 1) == (a_array[i + 1]))
        {
            a += c_array[a_array[i]];
        }
    }

    printf("%d", a);

    return 0;
}
