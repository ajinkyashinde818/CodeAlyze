#include<stdio.h>
#define N 200000

int main(){

    int k, n;
    int a[N];
    int max;
    int i;
    int index = 0;

    scanf("%d %d", &k, &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    max = k - a[n-1] + a[0];
    index = 0;

    for(i=1;i<n;i++){
        if(a[i]-a[i-1] > max){
            max = a[i]- a[i-1];
            index = i;
        }
    }

    printf("%d\n", k-max);
    
    
    

    return 0;
}
