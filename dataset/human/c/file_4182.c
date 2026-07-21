#include <stdio.h>
#define Min(a, b) a < b ? a : b
void initArray(int a[], int len);
int main(void)
{
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    int min = Min(a, b);
    int divisors[min];
    initArray(divisors, min);
    int count_divisors = 0;
    int first = 1, last = min;
    while(first <= last)
    {
        if (a % first + b % first == 0)
        {
            divisors[count_divisors] = first;
            count_divisors++;
        }
        first++;
    }
    printf("%d\n", divisors[count_divisors - k]);
    return 0;
}

void initArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
}
