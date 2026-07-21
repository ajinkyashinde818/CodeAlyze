#include <stdio.h>

int main(){
    int K,S;
    int X=0, Y=0, Z=0;
    int ans=0;

    scanf("%d %d", &K, &S);
        for (int j = 0; j <=K ; ++j) {
            for (int k = 0; k <=K ; ++k) {
                Z = S-k-j;
                if(0<= Z && Z <=K){
                    ans = ans + 1;
                }
            }
        }
    printf("%d", ans);
}
