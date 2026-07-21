#include <bits/stdc++.h>
using namespace std;
 
struct edge {int /*from,*/to,cost;};
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> PP;
typedef vector<int> VI;
typedef vector<long long int> VL;
typedef vector<edge> VE;
//static const int INF = 2147483647;
//static const long long INF = 9223372000000000000;
//static const long long INF = 9223372000000000000/2;
//static const long long INF = 9223372000000000000/2145;
//static const int INF = 1000010000;
//static const int NIL = -1;
//static const int MOD = 1000000007;
//int dx4[4] = {0,1,0,-1}, dy4[4] = {-1,0,1,0};
//int dx5[5] = {-1,0,0,0,1}, dy5[5] = {0,-1,0,1,0};
//int dx8[8] = {-1,0,1,1,1,0,-1,-1}, dy8[8] = {1,1,1,0,-1,-1,-1,0};
//int dx9[9] = {-1,0,1,1,1,0,-1,-1,0}, dy9[9] = {1,1,1,0,-1,-1,-1,0,0};
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define np next_permutation
#define pq priority_queue
#define int ll

signed main(){
    int n;
    int a[214514];
    scanf("%lld",&n);
    int sm = 0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sm += a[i];
    }

    int sn=a[0];
    int ar=sm-sn;
    int maxdiff = abs(sn-ar);
    for(int i=1;i<n-1;i++){
        sn += a[i];
        ar -=a[i];
        if(maxdiff>abs(sn-ar)) maxdiff=abs(sn-ar);
    }

    printf("%lld\n",maxdiff);
    return 0;
}
