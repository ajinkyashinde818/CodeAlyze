#include <stdio.h>

int main(void)
{
        int num[15000];
        int i = 0;
        
        do {
                i++;
                scanf("%d", &num[i]);
        } while (num[i] != 0);

        for (i = 1; num[i] != 0; i++) {
                printf("Case %d: %d\n", i, num[i]);
        }
        return 0;
}
