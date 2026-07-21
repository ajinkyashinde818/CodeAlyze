#include <stdio.h>

int main(void) {
    int R,G,B,N,i,j,ans = 0;
    scanf("%d %d %d %d",&R,&G,&B,&N);
    for (i = 0;i * R <= N;i++) {
        for (j = 0;i * R + j * G <= N;j++) {
            if ((N - i * R - j * G) % B == 0) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
