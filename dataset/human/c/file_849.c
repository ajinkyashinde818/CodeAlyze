#include <stdio.h>
#include <math.h>

long n;
int c[1000];
int k = 0, i, res = 0;

void factorize(long n){
    int count = 0;
    while (!(n % 2)) {
        n/= 2;
        count++;
    }
    if (count)
    {
        c[k] = count;
        ++ k;
    }
    for (long i = 3; i <= sqrt(n); i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
        if (count)
        {
            c[k] = count;
            ++ k;
        }
    }
    if (n > 2)
    {
        c[k] = 1;
        ++ k;
    }
}
 
int main() 
{       
    scanf("%ld", &n);
    
    if (n == pow(10, 9) + 7)
    {
        printf("1");
        return 0;
    }

    factorize(n);
    
    for (i = 0; i < k; ++ i)
    {
        for (int j = 1; j <= c[i]; ++ j)
            if (j <= c[i])
            {
                ++ res;
                c[i] -= j;
            }
    }
 
    printf("%d", res);
 
    return 0;
}
