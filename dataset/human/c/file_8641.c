#include <stdio.h>

int main(){
    int n, a[100000], i, cnt=0;

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    i=1;

    do{
        cnt++;

        if(a[i-1] == 2){
            printf("%d\n", cnt);
            return 0;
        }

        i = a[i-1];

    }while(cnt <= n);

    printf("-1\n");

    return 0;
}
