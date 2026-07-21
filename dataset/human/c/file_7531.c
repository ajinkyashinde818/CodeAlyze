#include <stdio.h>

int main()
{
    int input[10000];
    
    for (int i = 0; i < 10000; i++){
        scanf("%d", &input[i]);
        if (input[i] == 0) {
            break;
        }
        else {
            /* NOP */
        }

    }

    for (int j = 0; j < 10000; j++) {
        if (input[j] == 0) {
            break;
        }
        else {
            /* NOP */
        }

        printf("Case %d: %d\n", (j + 1), input[j]);
        
    }
}
