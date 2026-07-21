#include <stdio.h>

int main(void) {
        int N;
        int j1, j2;

        scanf("%d", &N);
        j1 = (int)(N / 10);
        j2 = (int)(N - j1 * 10);
        if(j1 == 9)
                printf("Yes");
        else if(j2 == 9)
                printf("Yes");
        else
                printf("No");

        return 0;
}
