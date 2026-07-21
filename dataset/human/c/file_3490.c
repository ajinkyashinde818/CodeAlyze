#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#define MAX 200010
typedef long long ll;
ll N,K,A[MAX];
ll loop_start=0,loop_end=0;
bool bit[MAX]={false};
ll memo[MAX];

void solve(ll town){
    bit[town] = true;
    memo[++loop_end] = town;
    if(bit[A[town]] == true){
        for(ll i=1;i<=loop_end;i++){
            if(memo[i] == A[town]){
                loop_start = i;
                break;
            }
        }
    }
    else solve(A[town]);
}
int main(){
    scanf("%lld %lld",&N,&K);
    for(ll i=1;i<=N;i++)
        scanf("%lld",A+i);
    solve(1);

    if(K-loop_start < 0){printf("%lld",memo[K+1]);}
    else
        printf("%lld",memo[loop_start + (K-loop_start+1)%(loop_end-loop_start+1)]);
}
