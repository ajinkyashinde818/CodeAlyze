#include<stdio.h>
int main(void){
    int i, n, min,max = -999999999;
    int R[200000];

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &R[i]);
    }

    min =R[0];
    for(int j = 1; j < n; j++){
        if(max < R[j] - min){ max = R[j] - min;}
        if(min > R[j]){ min = R[j];}
    }

    printf("%d\n", max);

    return 0;
}
