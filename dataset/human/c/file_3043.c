#include<stdio.h>
#define MAXN 200000

int main(){
    int k, n, distance, mindis;
    int a[MAXN];

    scanf("%d %d", &k, &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i=0; i<n; i++){
        if( i )
            distance = k-a[i]+a[i-1];
        else
            distance = a[n-1]-a[i];
        if( !i||distance<mindis )
            mindis = distance;
    }
    printf("%d", mindis);

    return 0;
}
