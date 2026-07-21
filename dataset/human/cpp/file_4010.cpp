#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

double dist(pair<ll,ll> a, pair<ll,ll> b){
    return sqrt(pow((double)a.first-b.first,2)+pow((double)a.second-b.second,2));
}

int main(){
    ll xs,ys,xt,yt;
    int N;
    cin >> xs >> ys >> xt >> yt;
    cin >> N;

    pair<ll,ll> V[1002];
    ll R[1002];
    V[0]=make_pair(xs,ys);
    R[0]=0;
    V[1]=make_pair(xt,yt);
    R[1]=0;

    for(int i=0;i<N;i++){
        ll x,y,r;
        cin >> x >> y >> r;
        V[i+2]=make_pair(x,y);
        R[i+2]=r;
    }

    double d[1002];
    d[0]=0.0;
    for(int i=1;i<N+2;i++) d[i]=INFINITY;
    int cnt=N+2;
    bool checked[1002];
    for(int i=0;i<N+2;i++) checked[i]=false;

    while(cnt>0){
        double mn=INFINITY;
        int mi=0;
        for(int i=0;i<N+2;i++){
            if(checked[i]==false && d[i]<mn){
                mn=d[i];
                mi=i;
            }
        }
        checked[mi]=true;
        cnt--;

        for(int i=0;i<N+2;i++){
            d[i]=min(d[i],d[mi]+max(0.0,dist(V[i],V[mi])-(R[i]+R[mi])));
        }
    }
    
    printf("%.12lf\n",d[1]);
    return 0;
}
