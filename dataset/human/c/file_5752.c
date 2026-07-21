#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,*R,maxv,minv;
    scanf("%d",&n);
    R = (int *)malloc(sizeof(int) * n);
    // read the integers
    for(int i = 0; i < n; i++){
        scanf("%d",&R[i]);
    }
#ifdef D
    for (int j = 0; j < n; j++) {
        printf("%d ",R[j]);
    }
    printf("\n");
#endif
    
    maxv = R[1] - R[0];
    minv = R[0];
    // search the max profit to compare a minimum R[i] to the others
    for(int i = 1; i < n; i++){
        maxv = (maxv > R[i] - minv ? maxv : R[i] - minv);
        minv = (minv < R[i] ? minv : R[i]);
    }
    
    printf("%d\n",maxv);
    
    free(R);
    
    return 0;
}
