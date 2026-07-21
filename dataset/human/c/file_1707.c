#include <stdio.h>

int main(void)
{
    int n;
    int a[100];
    int b[100];
    int c[100];
    int tensu=0;
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n;i++){
        scanf("%d", &b[i]);
    }

    for(i = 0; i < n-1; i++){
        scanf("%d", &c[i]);
    }

    for(i = 0; i < n; i++){
        tensu += b[a[i]-1];
        if(a[i+1] == a[i]+1){
            tensu += c[a[i]-1];
        }
    }

    printf("%d", tensu);


    return 0;
}
