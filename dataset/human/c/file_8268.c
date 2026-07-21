#include <stdio.h>
 
int main(void)
{
    int i, N, K;
    char str[11];
    scanf("%d", &N);
    scanf("%s", str);
    scanf("%d", &K);

    for (i = 0; i < N; i++){
        if(str[i] == str[K - 1]){
            continue;
        }else{
            str[i] = '*';
        }
    }
    printf("%s\n", str);
    return 0;
}
