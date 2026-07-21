#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#define MAX 1000004
typedef long long ll;
int main(){
    ll N,prime_index=0,prime_seq[MAX]={0};
    bool prime_flag[MAX];    //素数ならtrue;
    for(ll i=2;i<MAX;i++) prime_flag[i]=true;
    scanf("%lld",&N);
    //素数列作るよ
    for(ll i=2;i<MAX;i++){
        if(!prime_flag[i]) continue;
        for(ll j=2;i*j<MAX;j++)
            prime_flag[i*j]=false;
    }
    for(ll i=2;i<MAX;i++)
        if(prime_flag[i]) prime_seq[prime_index++]=i;
    //素数列作り終わったよ
    prime_index--;
    //素因数分解始まるよ
    ll prime_fac[MAX]={0},ans=0;
    bool f=false;
    while(N!=1){
        ll i=0;
        while(N%prime_seq[i]!=0 && prime_index>i)i++;
        if(prime_index<=i){
            ans++;
            break;
        }
        N/=prime_seq[i];
        prime_fac[prime_seq[i]]++;
        f=true;
    }
    //素因数分解終わったよ
    //総和のテーブル作るよ
    ll table[100];
    table[1]=1;
    for(ll i=2;i<=100;i++)
        table[i]=table[i-1]+i;
    //総和のテーブル作り終わったよ
    for(ll i=0;i<prime_index;i++){
        if(!prime_fac[prime_seq[i]]) continue;
        ll j=1;
        while(table[j]<=prime_fac[prime_seq[i]]) j++;
        ans+=j-1;
    }
    printf("%lld",ans);
    return 0;
}
