#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    long long int n = 0;
    int counter = 0;
    int tmp_counter = 0;

    scanf("%lld", &n);

    for (long long int i = 2; n != 1;)
    {
        tmp_counter = 0;

        if (i > pow(n, 0.5))
        {
            counter += 1;
            break;
        }

        while ((n%i) == 0)
        {
            n = n/i;
            tmp_counter ++;
        }

        for (int i = 1; tmp_counter >= i; i++)
        {
            counter ++;
            tmp_counter = tmp_counter - i;
        }

        if (i == 2)
        {
            i++;
        } else {
            i += 2;
        }
        
    }

    printf("%d", counter);

    return 0;
}
