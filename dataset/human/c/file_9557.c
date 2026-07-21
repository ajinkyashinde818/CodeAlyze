#include <stdio.h>
int main(void){
    int N,D,X;
    int i,y,z,T=0;
    scanf("%d\n%d %d\n",&N,&D,&X);
    for(i=0;i<N;i++){
        scanf("%d\n",&y);
        for(z=1;z<=D;z+=y){
            T++;
        }
    }
    T+=X;
    printf("%d\n",T);
}
