#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int cnt=0;
    int a, b;
    for(int i=0; i<N; i++) {
        scanf("%d %d", &a, &b);
        if(a==b) {
            cnt++;
            if(cnt==3) {
                printf("Yes");
                return 0;
            }
        } else cnt=0;
    }
    printf("No");
    return 0;
}
