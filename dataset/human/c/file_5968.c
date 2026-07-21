#include <stdio.h>
int max(int, int);
int min(int, int);
int main(){
    int sizu, minv, maxv;
    int i, j;
    scanf("%d",&sizu);
    int A[sizu];

    for(i = 0; i < sizu; i++){
        scanf("%d",&A[i]);
    }

    minv = A[0];
    maxv = -2000000000;

    for(j = 1; j < sizu; j++){
        maxv = max(maxv,A[j]-minv);
        minv = min(minv, A[j]);
    }

    printf("%d\n",maxv);

    return 0;
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}
