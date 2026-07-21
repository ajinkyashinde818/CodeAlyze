#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if(a >= b) return a;
    else return b; 
}

int min(int a, int b){
    if(a <= b) return a;
    else return b;
}

int main(void){
    int i,max_v,min_v;
    int n;
    int *array;
    scanf("%d", &n);

    array = (int *)malloc(n*sizeof(int));

    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }

    max_v = array[1] - array[0];
    min_v = array[0];

    for(i=1; i<n; i++){
        min_v = min(min_v, array[i-1]);
        max_v = max(max_v, array[i] - min_v);
    }

    printf("%d\n", max_v);
    return 0;
}
