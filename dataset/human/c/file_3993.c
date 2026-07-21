#include <stdio.h>

int main(){
    int a, b, k;
    int i, cnt = 0, yakusu[100];

    scanf("%d %d %d", &a, &b, &k);

    for(i=1; i<=100; i++){
        if(a % i == 0 && b % i == 0){
            yakusu[cnt] = i;
            cnt++;
        }
    }

    printf("%d\n", yakusu[cnt - k]);

    return 0;
}
