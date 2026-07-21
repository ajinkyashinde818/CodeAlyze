/*
 * FileName:     C
 * CreatedDate:  2020-03-28 21:10:40 +0900
 * LastModified: 2020-03-28 21:26:12 +0900
 */

#include <stdio.h>

int main(void){
    int K,N;
    scanf("%d %d",&K,&N);
    int A[N];
    int doko_max=0;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(i>0 && doko_max<A[i]-A[i-1]){
            doko_max=A[i]-A[i-1];
        }
    }
    if( K-A[N-1]+A[0]>doko_max ){
        doko_max=K-A[N-1]+A[0];
    }
    printf("%d\n",K-doko_max);
    return 0;
}
