#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#define MAX 1000000000
typedef long long ll;
int main(){
    ll N,K,S;
    scanf("%lld %lld %lld",&N,&K,&S);
    ll max = MAX;
    if(S==MAX) max--;
    ll ans[100002];
    for(ll i=0;i<K;i++)
        ans[i] = S;
    for(ll i=K;i<N;i++)
        ans[i] = max;
    for(ll i=0;i<N;i++)
        printf("%lld ",ans[i]);
}
