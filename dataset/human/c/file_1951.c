#include <stdio.h>

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d",&N);
    int a[N], b[N], c[N];
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d", &b[i]);
    }
    for(int i=0;i<N-1;i++){
        scanf("%d", &c[i]);
    }
    int bf = -2;
    int sc = 0;
    for(int i=0;i<N;i++){
        int now = a[i]-1;
        if(now == bf+1){
            sc += c[bf];
        }
        sc += b[now];
        bf = now;
    }
    printf("%d\n", sc);
    return 0;
}
