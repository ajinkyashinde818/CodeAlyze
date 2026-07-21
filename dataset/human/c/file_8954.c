#include<stdio.h>

int main(void)
{
    int n;
    int ans;

    while (1){
        scanf("%d", &n);

        if (n == 0){
            break;
        }
        
        ans = 0;

        while (1){
            if (n == 1){
                break;
            }

            if ((n % 2) == 0){
                n /= 2;
                ans++;
            }
            else {
                n *= 3;
                n++;
                ans++;
            }
        }

        printf("%d\n", ans);
    
    }

    return 0;
}
