#include<stdio.h>

int main(void)
{
        int n, k;
        int sum = 0;

        scanf("%d%d", &n, &k);

        int h[n];

        for(int i = 0; i < n; i++){
                scanf("%d", &h[i]);

                if(h[i] >= k){
                        sum++;
                }
        }

        printf("%d\n", sum);

        return 0;
}
