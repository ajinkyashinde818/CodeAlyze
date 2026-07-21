#include<stdio.h>
int main(void){
    long long int i,N,a,sa,sum=0;
    long long int A[100005]={0};
    scanf("%lld",&N);
    for(i=0;i<N;i++){
        scanf("%lld",&A[i]);
        sum+=A[i];
    }
    A[N]=A[0];
    if(sum%(N*(N+1)/2)!=0){printf("NO\n");return 0;}
    sa=sum/(N*(N+1)/2);
    for(i=0;i<N;i++){
        if((A[i]+sa-A[i+1])%N!=0||(A[i]+sa-A[i+1])<0){printf("NO\n");return 0;}
    }
    printf("YES\n");return 0;
}
