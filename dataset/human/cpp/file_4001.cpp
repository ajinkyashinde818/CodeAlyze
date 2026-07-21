#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
using namespace std::chrono;

/*
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
*/

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,r;


ld dists[1003][1003] = {0};

vector<ll> R;
vector<ll> X;
vector<ll> Y;


ld dist(ll x, ll y){
return sqrt(x*x + y*y);
}

ll SP[1003] = {0};

ld dijk(){

priority_queue<pair<ld,ll> > pq;
pq.push({0,0});

bool mark[1003] = {0};


while(!pq.empty()){

    pair<ld,ll> pa = pq.top();
    pq.pop();
    ld w = -pa.first;
    ll a = pa.second;

    if(mark[a] == 0){
        mark[a] = 1;
        if(a == 1)return w;
        for(ll c1 = 0; c1 < n; c1++){
            if(c1 != a && mark[c1] == 0){
                ld w2 = w + dists[a][c1];
                pq.push({-w2,c1});
            }

        }

    }

}
return -1;
}


int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll c1,c2,c3,c4,c5,c6;
    ll a,b,c,e;
    ll x;

    ll x1,y1,x2,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    cin >> n;
    n += 2;

    X.push_back(x1);
    Y.push_back(y1);
    X.push_back(x2);
    Y.push_back(y2);
    R.push_back(0);
    R.push_back(0);

    for(c1 = 0; c1 < n-2; c1++){
        cin >> x1 >> y1 >> a;
        X.push_back(x1);
        Y.push_back(y1);
        R.push_back(a);
    }


    for(c1 = 0; c1 < n; c1++){
        for(c2 = c1+1; c2 < n; c2++){
            ld di = dist(X[c1] - X[c2] , Y[c1] - Y[c2]);
            di = max(ld(0.0) , di-ld(R[c1]+R[c2]));
            dists[c1][c2] = di;
            dists[c2][c1] = di;
        }
    }

    cout << setprecision(18) << dijk() << "\n";

    return 0;
}
