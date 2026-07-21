#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<ld,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int sx,sy,tx,ty,N;
int X[1009], Y[1009], R[1009];
ld G[1009][1009];

ld dijkstra(int s,int t) {
    
    vector<ld> d(N,LLINF);
    vector<bool> visited(N,false);
    int u = s;
    d[u] = 0;
    
    while(u!=t){
        
        ld minv = LLINF;
        visited[u] = true;
        
        for(int i=0; i<N; i++){
            if( d[i]>d[u]+G[u][i] ){
                d[i] = d[u]+G[u][i];
            }
        }
        
        for(int i=0; i<N; i++){
            if( !visited[i] && d[i]<minv ) {
                u = i;
                minv = d[i];
            }
        }
    }
    return d[N-1];
}

ld dif(ld a,ld b){
    return abs(a-b);
}

ld calc(int i,int j){
    ld d=sqrt(pow(dif(X[i],X[j]),2)+pow(dif(Y[i],Y[j]),2));
    d-=R[i]+R[j];
    if(d<0) d=0;
    return d;
}

int main() {
    
    cin>>sx>>sy>>tx>>ty>>N;
    rep1(i,N) cin>>X[i]>>Y[i]>>R[i];
    N+=2;
    X[0]=sx, Y[0]=sy, X[N-1]=tx, Y[N-1]=ty;
    
    rep(i,N)for(int j=i+1;j<N;j++){
        ld d=calc(i,j);
        G[i][j]=G[j][i]=d;
    }
    
    ld ans=dijkstra(0,N-1);
    printf("%.10llf\n",ans);
}
