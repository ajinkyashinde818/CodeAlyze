#include <stdio.h>
#define for(v, a, n, b) for(int v=a; v<n; v+= b)

int n, d, x;
int a[120];

int main(){
    scanf("%d %d %d", &n, &d, &x);
    for(i, 0,n,1){
        scanf("%d", &a[i]);
    }
    int cant = 0;
    for(i, 0, n, 1){
        for(j, 1, d+1, a[i])
            cant += 1;
    }

    printf("%d\n", cant+x);
}
