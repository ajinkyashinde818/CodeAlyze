#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, j, k, c = 0;
    int K, S;
    scanf("%d %d", &K, &S);
    for ( i = 0; i <= K; i++ ){
        for ( j = 0; j <= K; j++ ){
            k = S - (i+j);
            if ( k >= 0 && k <= K ){
                c++;
            }
        }
    }
    printf("%d\n", c);
    return 0;
}
