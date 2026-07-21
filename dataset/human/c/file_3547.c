#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    int P[101];
    int p;
    int i;
    
    memset(P, 0, sizeof(P));

    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &p);
        P[p]++;
    }
    
    for (i = 99; i >= 1; i--){
        P[i] += P[i + 1];
    }
    
    for (i = 100; P[i] < i; i--);
    
    printf("%d\n", i);
    
    return (0);
}
