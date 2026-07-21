#include<stdio.h>

int main(){
    int n, tmp;
    int flag = 0;
    int cnt = 0;
    long int mark = 2147483647;
    long int sum = 0;
    scanf("%d\n", &n);
    int A[n], B[n];
    for(int i=0;i<n;i++){
            scanf("%d", &A[i]);
    }
    for(int i=0;i<n;i++){
        if(A[i]<0){
            B[i] = A[i] * -1;
            cnt++;
        }else if(A[i]==0){
            B[i] = A[i];
            flag = 1;
        }else{
            B[i] = A[i];
        }
    }
    for(int i=0;i<n;i++){
        if(B[i]<mark){
            mark = B[i];
        }
    }
    for(int i=0;i<n;i++){
        sum = sum + B[i];
    }
    if(cnt%2==1 && flag==0){
        sum = sum - (2*mark);
    }
    printf("%ld\n", sum);
    return 0;
}
