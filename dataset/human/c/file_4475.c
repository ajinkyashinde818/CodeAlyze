#include <stdio.h>

int main(void)
{
    int N, i;
    int D1[101], D2[101];

    scanf("%d",&N);
    for(i=0; i<N; i++) scanf("%d %d",&D1[i],&D2[i]);

    for(i=0; i<N-2; i++){
        if((D1[i]==D2[i])&&(D1[i+1]==D2[i+1])&&(D1[i+2]==D2[i+2])){
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}
