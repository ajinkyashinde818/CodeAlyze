#include<stdio.h>
int maxv(int, int[]);
int main(void){
    int n, a[200000], i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", maxv(n, a));
    return 0;
}
int maxv(int n, int a[]){
    int i,max,min;
    max=a[1]-a[0];
    min = a[0];
    for(i=1;i<n;i++){
        if(max < a[i] - min){
            max = a[i] -min;
        }
        if(min > a[i]){
            min = a[i];
        }
    }
    return max;
}
