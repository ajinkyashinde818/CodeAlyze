#include<stdio.h>
int main(){
    int K, S;
    int br=0;
    scanf("%d%d", &K, &S);
    
    for(int x=0; x<=K; x++){
            for(int y=0; y<=K; y++){
                    int z = S - x - y;
                            if(z>=0 && z<=K){
                                         br++;
                                         }
                    }
            }
    printf("%d", br);
    return 0;
}
