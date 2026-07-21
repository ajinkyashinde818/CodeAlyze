#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long

long long modpow(long long,long long);
ll combi(ll,ll);

int main(){
    ll x,y,keyx,keyy,key,ans;scanf("%lld%lld",&x,&y);
    if((-x+2*y)%3!=0 || (2*x-y)%3!=0 || (-x+2*y)<0 || (2*x-y)<0){//(x,y)を(1,2)と(2,1)の線形結合で表したときの係数は非負整数値
        printf("0\n");
        return 0;
    }
    keyx=(-x+2*y)/3;keyy=(2*x-y)/3;//線形結合の係数
    if(keyx<=keyy){key=keyx;}
    else if(keyy<=keyx){key=keyy;}

    ans=combi(keyx+keyy,key);//基底変換された座標系を考えて、最短ルートの計算
    printf("%lld\n",ans);
    return 0;
}

long long combi(long long n,long long r){//繰り返し二乗法を用いてcombination計算
    long long ans,i,under=1,up=1,mod=1000000007;
    for(i=1;i<=r;i++){
        under=under*i;
        under=under%mod;
    }
    under=modpow(under,mod-2);//フェルマーの小定理
    
    for(i=1;i<=r;i++){
        up=up*(n-i+1);
        up=up%mod;
    }
    ans=up*(under%mod);
    return ans%mod;
}

long long modpow(long long a,long long n){//繰り返し二乗法
    long long mod=1000000007;
    if(n==1) return a%mod;
    if(n%2==1) return (a*modpow(a,n-1))%mod;
    long long t=modpow(a,n/2);
    return (t*t)%mod;
}
