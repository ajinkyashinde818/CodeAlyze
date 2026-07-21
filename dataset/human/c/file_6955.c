#include <stdio.h>
 
int main(void)
{
    int H[300], W[300], i = 0, j, k, l;
    for(;;){
        scanf("%d%d", &H[i], &W[i]);
        if (H[i] == 0 && W[i] == 0) break;
        else i++;
    }
    for(j = 0; j < i ;j++){
        for(k = 0;k < H[j];k++){
            for(l = 0;l < W[j];l++){
                if ((k+l)%2 == 0) printf("#");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
     
    return 0;
}
