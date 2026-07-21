#include <stdio.h>

int main(void){
    int N, a, b;
    int count = 0;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d %d", &a, &b);
        if(a == b){
            count++;
            if(count >= 3){
                printf("Yes\n");
                return 0;
            }
        } else count = 0;
    }

    printf("No\n");

    return 0;
}
