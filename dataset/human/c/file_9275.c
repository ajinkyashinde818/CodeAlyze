#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    int H[n];

    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &H[i]);
    }

    int cnt = 0;
    for(i = 0; i < n; i++){
        if(H[i] >= k){
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
