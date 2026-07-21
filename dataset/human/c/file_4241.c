#include<stdio.h>

int main(void){
    int n, m, a, i, s[100000], b=1000000007;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n + 1; i++){
        s[i] = 1;
    }
    for(i = 0; i < m; i++){
        scanf("%d", &a);
        s[a] = 0;
    }


    for(i = 2; i < n + 1; i++){
        if(s[i] != 0){
            s[i] = s[i-1] + s[i-2];
            if(s[i] > b){
                s[i] %= b;
            }
        }
    }
    printf("%d", s[n]);
    return 0;
}
