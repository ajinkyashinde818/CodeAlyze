#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(void){
    int K, S;
    scanf("%d %d", &K, &S);
    int x, y, z;
    int count = 0;
    for(x=0; x<=K; x++) {
        for(y=x; y<=K; y++) {
            for(z=y; z<=K; z++) {
                if(x + y + z == S) {
                    if(x==y && y==z) {
                        count++;
                    }
                    else if((x!=y || y!=z) && ((x==y && y!=z) || (y==z && x!=y))) { 
                        count +=3;
                    }
                    else {
                        count +=6;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
