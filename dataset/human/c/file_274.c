#include <stdio.h>

int main(){
    long long int n;
    scanf("%lld", &n);

    long long int a[n];
    for(int i = 0;i < n;i++){
        scanf("%lld", &a[i]);
    }

    int nega = 0;
    for(int i = 0;i < n;i++){
        if(a[i] < 0){
            nega++;
        }
    }

    long long int r;
    long long int buffer = 1000000000;
    if(nega % 2 == 0){
        for(int i = 0;i < n;i++){
            if(a[i] >= 0){
                r += a[i];
            }else{
                r += (a[i] * -1);
            }
        }
    }else{
        for(int i = 0;i < n;i++){
            if(a[i] < 0){a[i] = a[i] * -1;}
            if(buffer > a[i]){buffer = a[i];}
        }
        for(int i = 0;i < n;i++){
            r += a[i];
        }
        r = r - (buffer * 2);
    }
    printf("%llu\n", r);
}
