#include<stdio.h>
#include<limits.h>

int main(){

    int n;
    scanf("%d", &n);

    int max = INT_MIN, min = INT_MAX,x;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        //max, minの両方記録しておく！
        if(max < x-min) max = x - min;
        if(min > x) min = x;
    }

    printf("%d\n", max);
    return 0;
}
