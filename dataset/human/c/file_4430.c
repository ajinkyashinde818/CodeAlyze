#include <stdio.h>
#include <stdbool.h>

int main(){
    int N;
    if(scanf("%d", &N)==1);
    if(N<3 || N>100){
        return -1;
    }

    int D1[128], D2[128];
    for(int i=0; i<N; i++){
        scanf("%d %d", &D1[i], &D2[i]);
    }

    bool hantei=false;   
    for(int i=0; i<N; i++){
        if( (D1[i]==D2[i]) 
            && (D1[i+1]==D2[i+1])
            && (D1[i+2]==D2[i+2]) ){
                hantei=true;
        }
    }

    if(hantei){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}
