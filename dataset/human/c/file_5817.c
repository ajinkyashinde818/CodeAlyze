#include<stdio.h>

int main()
{
    //????????????
    int n,i,R[200000],j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &R[i]);

    

    int maxv = R[1]-R[0];
    int minv = R[0];
        for (j = 1; j < n ; j++) {
        maxv = (maxv >= R[j] - minv) ? maxv : (R[j] - minv);
        minv = (minv >= R[j]) ? R[j] : minv;
        }

    printf("%d\n", maxv);


    return 0;
}
