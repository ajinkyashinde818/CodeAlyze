#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, sum = 0;
    int *a, *b, *c;
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    c = (int *)malloc((n - 1) * sizeof(int));
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    };
    for(i = 0; i < n; i++){
        scanf("%d", &b[i]);
    };
    for(i = 0; i < (n - 1); i++){
        scanf("%d", &c[i]);
    };
    sum += b[a[0] - 1];
    //printf("%d", b[a[0] - 1]);
    /*for(i = 0; i < n; i++){
        printf("a[%d] = %d, b[%d] = %d c[%d] = %d\n", i, a[i], i, b[i], i, c[i]);
    }*/
    //printf("sum = %d\n", sum);
    for(i = 1; i < n; i++){
        sum += b[(a[i] - 1)];
        //printf("%d turn : sum = %d\n", i, sum);
        if(a[i] - a[i - 1] == 1){
            sum += c[a[i - 1] - 1];
            //printf("** add = %d, sum = %d\n", c[a[i - 1] - 1], sum);
        }
    }
    printf("%d", sum);
}
