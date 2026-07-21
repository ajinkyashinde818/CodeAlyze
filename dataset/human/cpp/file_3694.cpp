#include <bits/stdc++.h>

using namespace std;
using ll =long long;
using db = double;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define leftunique(v) SORT(v);(v).erase(unique((v).begin(),(v).end()),(v).end())
//leftuniqueは配列から同じ要素のものを取り除く 例 4 6 2 1 3 4 1 2 なら 1 2 3 4 6 になる
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
bool coY() {cout <<"Yes"<<endl;}
bool coN(){cout <<"No"<<endl;}
const int mod = 1e9 + 7;

ll ans;
//ここから書き始める
int main()
{
	cout << setprecision(10);
	int n ;cin  >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];

	int count = 0;
	ll ans = 0;
	ll m = abs(v[0]);
	rep(i,n){
		if(v[i]<0){
			count ++ ;
		}
		ans += abs(v[i]);
		chmin(m,abs(v[i]));
	}
	if(count %2 ==1 ){
		ans -= 2 * m;
	}
	cout << ans << endl;

}
