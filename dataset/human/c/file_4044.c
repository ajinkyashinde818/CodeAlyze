#include<stdio.h>

int main(void)
{

        int a, b, k, s, i;

        scanf("%d%d%d", &a, &b, &k);

        for(i=100; i>=1; i--){
                if((a%i==0) && (b%i==0))
                        s++;
                if(s==k) break;
        }
        printf("%d\n", i);
        return 0;
}
