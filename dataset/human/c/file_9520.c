#include<stdio.h>
int main()
{
    int n, d, x, j,k,p=0;
    scanf("%d", &n);
    scanf("%d %d", &d, &x);
    int a[n], i;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    i=0;
    for(k = 0; k <n; k++){
        for(j = 0;; j++){

            if((j*a[i]+1) <= d) p++;
            if((j*a[i]+1) > d) break;
        } i++;
    }
    printf("%d\n", p+x);
    return 0;
}
