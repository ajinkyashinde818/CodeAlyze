#include <stdio.h>
int main(void){
    int K, S, count=0;
    scanf("%d%d",&K,&S);
    for(int x=0; x<=K; x++){
        for(int y=0; y<=K; y++){
            int z = S-x-y;
            if(S==x+y+z && z>=0 && z<=K) count++;
        }
    }
    printf("%d", count);
    return 0;
}
