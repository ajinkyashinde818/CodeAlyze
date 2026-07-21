#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1,0};
const int dy[]={0,1,0,-1,1,1,-1,-1,0};
const int INF = 1e9+101;
const long long LINF = 1e18;
const double EPS = 1e-8;
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define reps(i,j,k) for(ll i = (j); i < (k); ++i)
#define rep(i,j) reps(i,0,j)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> Pii;
typedef pair<Pii,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
template<class T>
ostream& operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()){
		out << v[i] <<", ";
	}
	return out << "}" << endl;
}

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll a = LINF;
    int idx = -1;
    ll ans = 0;
    int ret = 0;
    int zr = 0;
    rep(i,N){
        cin >> A[i];
        if (a > abs(A[i])) {
            a = abs(A[i]);
            idx = i;
        }
        if(A[i] < 0) {
            ret++;
        }
        if(A[i] == 0){
            zr++;
        }
    }

    if(ret % 2 == 0 || zr > 0) {
        rep(i,N){
            ans += max(A[i], -A[i]);
        }
    } else {
        rep(i,N){
            if(i == idx) ans += -a;
            else{
                ans += max(A[i], -A[i]);
            }
        }
    }

    printf("%lld\n",ans);

    return 0;  
}
