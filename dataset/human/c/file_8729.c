#include<stdio.h>

int main(void){
    int n, now, a, count, b[100001];

    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++) scanf("%d", &b[i]);

    count = 0;
    now = 1;
    while(now != 2){
        a = b[now];
        b[now] = -1;
        if(a < 0){
            count = -1;
            break;
        }else{
            now = a;
            count++;
        }
    }
    printf("%d", count);

    
    return 0;
}
