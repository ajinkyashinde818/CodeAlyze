#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


int N;
ll C;
ll X[101000];
ll V[101000];

pll normal_round[100010];
pll rev_round[100010];


class RMQ{
public:
    int n;
    vector<ll> dat;
    // 初期化
    void init(int n_){
        n=1;
        while(n<n_)n*=2;
        dat.resize(n * 2 - 1, LONG_LONG_MIN / 100);
    }
    // k番目の値(0-indexed)をaに変更
    void update(int k,ll a){
        // 葉の節点
        k+=n-1;
        dat[k]=a;
        // のぼりながら更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[k*2+1],dat[k*2+2]);
        }
    }
    // [a,b)の最大値を求める
    // kは節点の番号、l,rはその節点が[l,r)に対応づいていることを表す
    // したがって、外からはquery(a,b,0,0,n)として呼ぶ
    ll _query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return LONG_LONG_MIN / 100;
        else if(a<=l&&r<=b)return dat[k];
        ll vl=_query(a,b,k*2+1,l,(l+r)/2);
        ll vr=_query(a,b,k*2+2,(l+r)/2,r);
        return max(vl,vr);
    }
    ll query(int a,int b){
        return _query(a,b,0,0,n);	
    }
};

RMQ rmq[2];

int main(){

    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> X[i] >> V[i];
    rmq[0].init(N);
    rmq[1].init(N);

    ll normal_opt = 0;
    ll rev_opt = 0;
    
    for(int i = 0; i < N; i++){
        if(i == 0){
            normal_round[i].first =  X[i];
            normal_round[i].second = V[i];
        }
        else{
            normal_round[i].first =  X[i];
            normal_round[i].second = V[i] + normal_round[i-1].second;
        }
        rmq[0].update(i, -normal_round[i].first + normal_round[i].second);
        normal_opt = max(normal_opt, -normal_round[i].first + normal_round[i].second);
    }
    for(int i = N - 1; i >= 0; i--){
        if(i == N - 1){
            rev_round[i].first =  C - X[i];
            rev_round[i].second = V[i];
        }
        else{
            rev_round[i].first =  C - X[i];
            rev_round[i].second = V[i] + rev_round[i+1].second;
        }
        rmq[1].update(i, -rev_round[i].first + rev_round[i].second);
        rev_opt = max(rev_opt, -rev_round[i].first + rev_round[i].second);
    }
    
    ll opt = max(normal_opt, rev_opt);

    for(int i = 0; i < N; i++){
        ll val = rmq[0].query(i, i + 1) - X[i] + rmq[1].query(i + 1, N);
        opt = max(opt, val);
    }
    for(int i = N - 1; i >= 0; i--){
        ll val = rmq[1].query(i, i + 1) - (C - X[i]) + rmq[0].query(0, i);
        opt = max(opt, val);
    }

    cout << opt << endl;

}
