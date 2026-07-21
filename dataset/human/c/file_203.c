#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    int multi = 1;
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
        if(a[i] < 0){
            multi = multi * (-1);
        }
    }
    if(multi > 0){
        long int sum = 0;
        for(int i = 0;i < n;i++){
            sum = sum + abs(a[i]);
        }
        printf("%ld\n", sum);
    }else{
        int min = abs(a[0]);
        for(int i = 1;i < n;i++){
            if(abs(a[i]) < min){
                min = abs(a[i]);
            }
        }
        long int sum = 0;
        for(int i = 0;i < n;i++){
            sum = sum + abs(a[i]);
        }
        printf("%ld\n", sum-2*min);
    }
    return 0;
}
