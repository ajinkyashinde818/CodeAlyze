#include <stdio.h>
#include <stdlib.h>

int main (void){
    int i,m=0,min=1e9;
    long long int ans=0;
    int N; 

    scanf("%d",&N);

    long long int A[N]; 

    for(i=0;i<N;i++){
        scanf("%lld",&A[i]);
        if(A[i]<0)m++;
        int a = abs(A[i]);
        ans += a;
        if(min>a){min=a;}
    }

    if(m%2==0){
        printf("%lld\n",ans);
    }
    else{
        printf("%lld\n",ans-2*min);
    }

    return 0;
}
