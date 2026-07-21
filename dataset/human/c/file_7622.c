#include<stdio.h>
#define MAX 10000

int main(){
    int x[MAX];
    int i;

    for(i = 0; i < MAX; i++){
        scanf("%d", &x[i]);
        if(x[i] == 0) break;
    }

    for(i = 0; i < MAX; i++){
        if(x[i] == 0) break;
        printf("Case %d: %d\n", i + 1, x[i]);
    }
    return 0;
}
