#include<stdio.h>

long long GCD(long long A,long long B){

    if(A < B){
        int i = A;
        A = B;
        B = i;
    }

    long long temp;

    while(A % B != 0){
        temp = B;
        B = A % B;
        A = temp;
    }

    return B;
}

long long LCM(long long  A,long long B){

    long long ans = (A * B) / GCD(A, B);
    return ans;
}

int main(){

    int A, B;
    scanf("%d%d", &A, &B);

    printf("%ld\n", LCM(A, B));

    return 0;
}
