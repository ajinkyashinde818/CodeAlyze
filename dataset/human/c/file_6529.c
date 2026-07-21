/*
 * FileName:     maximum_profit_fix_2
 * CreatedDate:  2020-07-14 00:06:00 +0900
 * LastModified: 2020-07-14 00:15:48 +0900
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;scanf("%d", &n);
    long int *r = malloc(n*sizeof(long int));
    for(int i=0; i<n; i++)scanf("%ld", r+i);
    long int minv = r[0];
    long int maxv = -1000000000;
    long int ans = maxv-minv;
    for(int i=1; i<n; i++){
        maxv = r[i];
        if(maxv-minv>ans){
            ans = maxv - minv;
        }
        if(minv > r[i]){
            minv = r[i];
        }
    }
    printf("%ld\n", ans);
    free(r);
    return 0;
}
