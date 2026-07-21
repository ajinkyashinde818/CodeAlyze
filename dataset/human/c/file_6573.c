#include<stdio.h>

int max1(int a, int b){
    if(a<b){
        return b;
    }else{
        return a;
    }
}

int min1(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int n;
    int R[210000];
    int i;
    int maxv = -1100000000;
    int minv;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &R[i]);
    }

    minv = R[0];

    for(i=1; i<n; i++){
        maxv = max1(maxv, R[i]-minv);
        minv = min1(minv, R[i]);
    }

    printf("%d\n", maxv);

    return 0;
}
