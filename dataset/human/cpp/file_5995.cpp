#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>

using namespace std;

#define INT_MAX_VALUE 2147483647
#define LONG_LONG_MAX_VALUE 9223372036854775807
#define ll long long

struct XX{
    ll la;
    ll lb;
    ll ra;
    ll rb;
    ll q;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.q) == (riRight.q)){
            return riLeft.q < riRight.q;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.q) < (riRight.q);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}

int asum(string P){
    int sum=0;
    int strength=1;
    for(int i=0;i<P.size();i++){
        if(P.substr(i,1)=="S"){
            sum+=strength;
        }else{
            strength*=2;
        }
    }
    return sum;
}

int n;
//int dat[2*10000000];
//int dat2[2*10000000];
int dat[2*100];
int dat2[2*100];

void init(int n_){
    n=1;
    while(n<n_)n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
        dat2[i]=0;
    }
}

void initset(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=dat[k*2+1]+dat[k*2+2];
    }
}

//[a,b)の間を[l,r]区間で比較しアップデート
//引数のindexに注意
//nは固定。initで計算すみ
//update2(L[i],R[i]+1,0,0,n,D[i]);
void update2(int a,int b,int k,int l,int r,int v){//v更新値、区間は0-index
    if(r<=a || b<=l)return;
    if(a<=l && r<=b){
        dat[k]+=dat2[k];
        if(r-l>1){
            dat2[k*2+1]+=dat2[k]/2;
            dat2[k*2+1]+=dat2[k]/2;
        }
        dat2[k]=v*(r-l);
        return;
    }else{
        update2(a,b,k*2+1,l,(l+r)/2,v);
        update2(a,b,k*2+2,(l+r)/2,r,v);
        return;
    }
}

int query(int a,int b,int k,int l,int r){
    if(r<=a || b<=l)return 0;
    if(a<=l && r<=b){
        dat[k]+=dat2[k];
        if(r-l>1){
            dat2[k*2+1]+=dat2[k]/2;
            dat2[k*2+1]+=dat2[k]/2;
        }
        dat2[k]=0;
        return dat[k];
    }
    else{
        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);
        return vl+vr;
    }
}


int dp[10005][10005];//Aの個数、Bの個数

int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs( "1_06.txt" );//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,C;
    cin >> N >> C;
    ll x[100000];
    ll y[100000];
    ll v[100000];
    for(int i=0;i<N;i++){
        cin >> x[i] >> v[i];
    }
    for(int i=0;i<N;i++){
        y[i]=C-x[i];
    }

    ll lmax[100000];
    ll tmp=0;
    for(int i=0;i<N;i++){
        if(i!=0){
            lmax[i]=max(lmax[i-1],tmp+v[i]-x[i]);
        }else{
            lmax[i]=max(tmp,tmp+v[i]-x[i]);
        }
        tmp=tmp+v[i];
    }
    ll rmax[100000];
    tmp=0;
    for(int i=0;i<N;i++){
        if(i!=0){
            rmax[N-1-i]=max(rmax[N-1-i+1],tmp+v[N-1-i]-y[N-1-i]);
        }else{
            rmax[N-1-i]=max(tmp,tmp+v[N-1-i]-y[N-1-i]);
        }
        tmp=tmp+v[N-1-i];
    }
    
    ll ans=0;
    ll sum=0;
    ans=max(ans,lmax[N-1]);
    for(int p=0;p<N;p++){//p反時計戻る
        if(p==N-1){
            ans=max(ans,sum+v[N-1-p]-y[N-1-p]);
        }else{
            ans=max(ans,sum+v[N-1-p]-2*y[N-1-p]+lmax[N-1-p-1]);
            sum=sum+v[N-1-p];
        }
    }
    sum=0;
    ans=max(ans,rmax[0]);
    for(int p=0;p<N;p++){//p時計行く
        if(p==N-1){
            ans=max(ans,sum+v[p]-x[p]);
        }else{
            ans=max(ans,sum+v[p]-2*x[p]+rmax[p+1]);
            sum=sum+v[p];
        }
    }
    cout << ans << endl;
    
    //ここまで
    //cout << "ans" << endl;改行含む
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
