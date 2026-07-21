#include <stdio.h>

#define Num 200000
int main(void){

    int l, n, i, j, max, min;
    int a[Num];

    scanf("%d", &l); 

    for(i = 0; i <= l-1; i++){
        scanf("%d", &n); 
        a[i] = n;
    }

    max = a[1] - a[0];
    if(a[1] > a[0]){
        min = a[0];
    }else{
        min = a[1];
    }

    for (i = 2; i <= l-1; i++) {
        if (a[i] < min){
            min = a[i];
        }else if(max < a[i]-min) {
            max = a[i]-min;
        }
    }

    printf("%d\n", max);

    return 0;
}
