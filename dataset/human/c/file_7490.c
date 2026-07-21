#include <stdio.h>
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main(){
    int A[10000];
    int count = 0;
    while(1){
        int a;
        scanf("%d", &a);
        if(a == 0) break;
        A[count] = a;
        count++;
    }

    rep(i, 0, count) printf("Case %d: %d\n", i + 1, A[i]);

    return 0;
}
