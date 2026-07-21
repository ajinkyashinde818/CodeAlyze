#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i = 0, cnt = 0, num = -1;
    int *ary = malloc(sizeof(int) * 10000);

    while (num != 0){
        scanf("%d", &num);
        ary[cnt] = num;
        cnt++;
    }

    for (i = 0; i < cnt-1; i++){
        printf("Case %d: %d\n", i+1, ary[i]);
    }
}
