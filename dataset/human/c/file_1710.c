#include <stdio.h>

int main() {
    int n,satisfaction;
    satisfaction = 0;
    scanf("%d",&n);
    //printf("%d\n",n);
    int a[22],b[22],c[22];

    //SCANNING
    for (int i=0; i < n; ++i){
        scanf("%d", &a[i]);
        --a[i];
        //printf("%d ", a[i]);
    }
    //printf("\n");
    for (int i=0; i < n; ++i){
        scanf("%d", &b[i]);
        //printf("%d ", b[i] );
    }
    //printf("\n");
    for (int i=0; i < n-1; ++i){
        scanf("%d", &c[i]);
        //printf("%d ", c[i]);
    }
    //printf("\n");

    //RUNNING THE BUFFET
    for (int i=0; i < n; ++i){
        if (i != n-1) {
            if ((a[i+1] - a[i]) == 1) {
                satisfaction = satisfaction + b[a[i]] + c[a[i]];
            } else {
                satisfaction = satisfaction + b[a[i]];
            }
        } else {
            satisfaction = satisfaction + b[a[i]];
        }
    }
    printf("%d\n", satisfaction);
    return 0;
}
