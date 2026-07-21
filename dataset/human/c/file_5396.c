#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){
    int N,M,X;
    scanf("%d %d %d",&N,&M,&X);
    int C[N],A[N][M];
    int S[M];
    int min=1000000000,S_m;
    for (int i=0; i<N; i++) {
        scanf("%d",&C[i]);
        for (int j=0; j<M; j++) {
            scanf("%d",&A[i][j]);
        }
    }
    for (int i=0; i<(1<<N); i++) {
        for (int j=0; j<M; j++) {
            S[j]=0;
        }
        S_m=0;
        for (int k=0; k<N; k++) {
            if(i & (1<<k)){
                for (int l=0; l<M; l++) {
                    S[l]+=A[k][l];
                }
                S_m+=C[k];
            }
        }
        int f=1;
        for (int o=0; o<M; o++) {
            if(S[o]<X){
                f=0;
                break;
            }
        }
        if (f) {
            if (S_m<min) {
                min=S_m;
            }
        }
        
    }
    if (min==1000000000) {
        printf("-1\n");
    }
    else{
        printf("%d\n",min);
        
    }
    return 0;
}
