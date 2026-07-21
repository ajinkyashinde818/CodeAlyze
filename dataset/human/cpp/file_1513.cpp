#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
#ifdef VC
#define scanf scanf_s
#endif
#define iINF (1<<30)
#define INF (1LL<<59)
#define forn(i) for(int i = 0;i < n; ++i)
#define form(i,n) for(int i = 0 ;i < n; ++i)
#define NIL -1

const ll mod = 998244353;
int n;
int m;
int ans = 0;

int main(){
	cin >> n;
	bool flg = false;
	for (int i = 1; i*(i + 1) <= 2 * n; i++) {
		if (i*(i + 1) == 2 * n) {
			flg = true;
			m = i;
			break;
		}
	}
	if (!flg) {
		cout << "No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	cout << m + 1 << endl;
	for (int i = 0; i < m+1; i++) {
		cout << m;
		int pr=i;
		for (int j = 0; j < i; j++) {
			cout << " "<<pr ;
			pr += m - j - 1;
		}
		pr += 1;
		for (int j = 0; j < m - i; j++) {
			cout << " "<< pr;
			pr++;
		}
		cout << endl;
	}
	return 0;
}
