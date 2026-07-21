#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
ll N, C;
ll x[100010];
ll v[100010];

ll sfd[100010], sbd[100010];
ll td;

/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>N>>C;
    REP(i,0,N){
        cin>>x[i+1]>>v[i+1];
    }

    //出発点からのiまでの最大得点
    td = 0LL;
    REP(i,1,N+1){
        td += v[i];
        sfd[i] = max({sfd[i-1], sfd[i], td-x[i]});
    }

    td = 0LL;
    REP(i,1,N+1){
        ll ii = N - i + 1;
        td += v[ii];
        sbd[i] = max({sbd[i-1], sbd[i], td-(C-x[ii])});
    }

    //時計回り開始
    ll ans = 0;
    td = 0LL;
    REP(start,0,N+1){
        if(start > 0) td += v[start];

        ll sum1 = td ;
        if(start > 0) sum1 -= x[start];
        if(start < N){
            ll rmx1 = sbd[N-start] - x[start];  //TODO: startで止まるとは限らない!!!（"先に計算した最適なインデックス < start" の場合がある）=> 固定する側で事前計算の値は使えない.
            if(rmx1 > 0){
                sum1 += rmx1;
            }
        }

        ans = max(ans, sum1);
    }

    //反時計回り開始
    td = 0LL;
    REP(start,0,N+1){
        ll s = N-start+1;
        if(start > 0) td += v[s];

        ll sum2 = td;
        if(start > 0) sum2 -= (C-x[s]);
        if(start < N){
            ll rmx2 = sfd[N-start] - (C - x[s]);
            if(rmx2 > 0){
                sum2 += rmx2;
            }
        }

        ans = max(ans, sum2);
    }

    cout<<ans<<endl;

    return 0;
}
