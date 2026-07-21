#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n;
	cin >> n;
	// if(n == 1){
	// 	cout << "Yes" << endl;
	// 	cout << 1  << " " << 1 << endl;
	// 	cout << 1  << " " << 1 << endl;
	// }
	int nn = n;
	int s = 0;
	for(int i = 1; i <= n; i++){
		nn -= i;
		if(nn < 0){
			cout << "No" << endl;
			return 0;
		}
		if(nn == 0){
			s = i;
			break;
		}
	}

	int k = 2*n/ s;
	int ss = s;
	// cout << "k = " << k << endl;
	// cout << "s = " << s << endl;

	vector<vector<int> > ans(k+1);
	vector<int> cnt(n+1,0);
	int now = 1;
	for(int i = 1; i <= k; i++){
		//cout << "now = " << now  <<endl;
		for(int j = now; j <= now+s-1; j++){
			ans[i].push_back(j);
		}
		for(int j = i+1; j <= k; j++){
			ans[j].push_back(now);
			now++;
		}
		s--;
	}

	cout << "Yes" << endl;
	cout << k << endl;
	for(int i = 1; i <= k; i++){
		cout << ss << " ";
		for(int j = 0; j < ss; j++){
			if(j != ss-1) cout << ans[i][j] << " ";
			else cout << ans[i][j] << endl;;
		}
	}

	return 0;
}
