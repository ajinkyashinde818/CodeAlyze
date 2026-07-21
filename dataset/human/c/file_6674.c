#include<stdio.h>

int main(){
    int n, r[200000];
    int i, j, maxv, minv;
    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &r[i]);

    maxv = r[1] - r[0];
    minv = r[0];
    for(j=1;j<n;j++){
        if(r[j]-minv > maxv) maxv = r[j]-minv;
        if(r[j] < minv) minv = r[j];
    }
    /* for(i=n-1;i>0;i--){ */
    /*     #<{(| if(r[i] < max) break; |)}># */
    /*     for(j=i-1;j>=0;j--){ */
    /*         if(r[i]-r[j] > max){ */
    /*             max = r[i]-r[j]; */
    /*         }  */
    /*     } */
    /* } */
    printf("%d\n", maxv);
    return 0;
}
