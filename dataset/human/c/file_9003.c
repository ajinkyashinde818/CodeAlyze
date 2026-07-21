// AOJ Volume 1 Problem 0158 Collatz's Problem


#include <stdio.h>

int main(void)
{
    int n;
    int times;
    
    while (1){
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        
        times = 0;
        while (n != 1){
            if (n % 2 == 0){
                n /= 2;
            }
            else {
                n = n * 3 + 1;
            }
            times++;
        }
        printf("%d\n", times);
    }
    
    return (0);
}
