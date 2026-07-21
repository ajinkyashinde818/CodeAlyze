// AOJ Volume 0 Problem 0053

#include <stdio.h>

int flg_prime[1000001];

int main(void)
{
    int i;
    int j;
    int n;
    int sum;
    
    flg_prime[0] = flg_prime[1] = 1;
    for (i = 2; i <= 1000000; i++){
        if (flg_prime[i] == 0){
            j = i * 2;
            while (j <= 1000000){
                flg_prime[j] = 1;
                j += i;
            }
        }
    }

    while (1){
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        
        sum = 0;
        i = 0;
        while (n > 0){
            if (flg_prime[i] == 0){
                sum += i;
                n--;
            }
            i++;
        }

        printf("%d\n", sum);
    }

    return (0);
}
