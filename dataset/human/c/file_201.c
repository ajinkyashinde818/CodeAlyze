#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 2147483647

int func(int x){
    return x<0?-1 * x: x;
}


int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    int cnt = 0;
    int min = INT_MAX;
    long long int sum = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(a[i] < 0){
            cnt++;
        }
        if(min > func(a[i])){
            min = func(a[i]);
        }
        sum += func(a[i]);
    }
    if(cnt % 2){
        sum -= 2*min;
    }
    printf("%lld", sum);

    return 0;
}
