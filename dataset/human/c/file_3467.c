/*
 * FileName:     D_fix
 * CreatedDate:  2020-07-04 01:20:42 +0900
 * LastModified: 2020-07-04 02:02:44 +0900
 */

#include <stdio.h>
#include <stdlib.h>
int main(void){
    long int n, k;scanf("%ld%ld", &n, &k);
    long int *a = malloc((n+1)*sizeof(long int));
    for(long int i=1;i<n+1;i++)scanf("%ld", a+i);
    long int *order = malloc((n+1)*sizeof(long int));
    for(long int i=1;i<n+1;i++)order[i]=0;
    long int s = 1, cnt = 0;
    while(order[s]==0){
        order[s]=cnt++;
        s = a[s];
    }
    long int cycle = cnt-order[s];
    long int ini = cnt-cycle;
//    printf("%d,%d\n",ini,cycle);
    if(ini>k){
        for(long int i=0;i<n;i++){
            if(order[i]==k){
                printf("%ld\n",i);
                free(a);
                return 0;
            }
        }
    }
    long int cycle_gun = (k-ini)%cycle+ini;
    for(long int i=0;i<n+1;i++){
        if(order[i]==cycle_gun){
            printf("%ld\n",i);
        }
    }
    free(a);
    return 0;
}
