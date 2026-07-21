#include <stdio.h>
int main(void){
    int N, K, C;
    int ch, i, j;
    int workday[200000] = {0};

    scanf("%d%d%d%*c", &N, &K, &C);
    for(i = 0; i < N; i++){
        ch = getchar();
        if(ch == 'x')
            workday[i] = -1;
    }

    j = N - 1;
    for(i = K; i >= 1; i--){
        while(workday[j] == -1)
            j--;
        workday[j] = i;
        j -= C + 1;
    }

    j = 0;
    for(i = 1; i <= K; i++){
        while(workday[j] == -1)
            j++;
        if(i == workday[j])
            printf("%d\n", j+1);
        j += C + 1;
    }

    return 0;
}
