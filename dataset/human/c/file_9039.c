#include<stdio.h>
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    int h[100000];
    for(int i=0; i<N; i++){
            scanf("%d", &h[i]);
            }
    int br=0;
    for(int i=0; i<N; i++){
            if(h[i]>=K) br++;
            }
    printf("%d", br);
    return 0;
}
