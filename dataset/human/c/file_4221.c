#include<stdio.h>
#include<math.h>

int main(void){
    int N,M,i,j,t;
    long long int s = 1;
    scanf("%d %d",&N,&M);
    int a[M+1];
    long long int p[N+2];
    p[0] = 0;
    p[1] = 1;
    a[0] = -1;
    for(i = 2;i<=N+1;i++) p[i] = (p[i-2] + p[i-1]) % 1000000007;
    if(M > 0){
        for(j = 1;j <= M;j++){
            scanf("%d",&a[j]);
            s = s * p[a[j]-a[j-1]-1] % 1000000007;
        }
        s = s * p[N-a[M]] % 1000000007;
    }else{
        s = p[N+1] % 1000000007;
    }
    printf("%lld",s);
    return 0;
}
