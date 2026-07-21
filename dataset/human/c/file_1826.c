#include <stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int i,j;
    int A[100];
    int B[100];
    int C[100];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&j);
        A[i]=j;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&j);
        B[i]=j;
    }
    for(int i=0;i<n-1;i++){
        scanf("%d",&j);
        C[i]=j;
    }
    j=1000000;
    for(int i=0;i<n;i++){
        count+=B[i];
        if(A[i]==j+1){
            count+=C[j-1];
        }
        j=A[i];
    }
    printf("%d",count);
    return 0;
}
