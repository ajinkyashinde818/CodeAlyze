#include <bits/stdc++.h>

using namespace std;
using ll =long long;
using db = double;
using vll = vector<long long>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define leftunique(a) {SORT(a);(a).erase(unique((a).begin(),(a).end()),(a).end());}
//leftuniqueは配列から同じ要素のものを取り除く 例 4 6 2 1 3 4 1 2 なら 1 2 3 4 6 になる
#define debug(x)  cout << #x << " = " << (x) << endl;
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
bool coY() {cout <<"Yes"<<endl;}
bool coN(){cout <<"No"<<endl;}
const int mod = 1e9 + 7;
const ll INF = 1LL << 60;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//グラフ用
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};	
//ここから書き始める

ll combination(ll n, ll i){
	ll count = 0;
	ll multi = 1;
	ll div =1;
	int limit = i;
	while(count < limit){
		multi *= n;
		n--;
		multi/= count+1;
		count ++ ;
	}
	return multi / div;
}

int main()
{
	cout <<setprecision(10);
	ll N ; cin >> N;
	vector<ll> a(N);
	rep(i,N) cin >> a[i];

	//ソートは出来ない。
	ll S = 0;
	rep(i,N){
		S += a[i];
	}
	//一番好ましいのは、 S / 2 にすること
	ll prefer = S / 2 ;
	ll sunuke = 0;
	ll ans = INF;
	rep(i,N-1){
		sunuke += a[i];
		if(sunuke < S / 2){
			chmin(ans,abs(sunuke - (S -sunuke)));
		}else{
			chmin(ans,abs(sunuke - (S - sunuke)));
		}
	}
	cout << ans << endl;


}
