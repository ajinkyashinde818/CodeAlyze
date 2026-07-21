#include<stdio.h>

int main(void)
{
        int a, b, k, n, i, c=0;

        scanf("%d%d%d", &a,&b,&k);

        if(a > b) {
                n = a;
        } else {
                n = b;
        }

        for(i = n; i >= 1; i--) {
                if(a%i==0 && b%i==0) {
                        c++;
                        if(c == k) {
                                printf("%d", i);
                                return 0;
                        }
                }
        }
}
