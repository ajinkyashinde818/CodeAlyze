#include <stdio.h>

int main(void){
    int K, S, count=0;

    scanf("%i %i", &K,&S);

    for(int x=0; x<=K; x++){
        for(int y=0; y<=K; y++){
            int z=S-x-y;
                if (0<=z && z<=K) count++;
        }
    }   

    printf("%i\n", count);
    return 0;
}
