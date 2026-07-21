#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <string.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 1000000000
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define sove(v) sort((v).begin(),(v).end());
typedef long long int ll;
using namespace std;
int main(){

	int n, r; cin >> n >> r;
	if (n < 10) { cout << r + (100 * (10 - n)) << endl; }
	else { cout << r << endl; }

	return 0;
}

/*#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void) {

	int n; cin >> n;
	string s[110];
	string ans;
	for (int i = 0; i < n; i++) { cin >> s[i]; }
	ans += s[0];
	for (int i = 1; i < n; i++) {
		int dabu = 0;
		for (int j = 0; j <= min(ans.size(), s[i].size()); j++) {
			string r, l;
			int mae = ans.size()- j;
			for (int k = 0; k < j; k++) {
				l.push_back(ans[mae + k]);
				r.push_back(s[i][k]);
			}
			cout << l << " "  << r << endl;

			if (l == r) { dabu = j; }
		}
		for (int j = dabu; j < s[i].size(); j++) {
			ans.push_back(s[i][j]);
		}
	}
	cout << ans << endl;

	return 0;
}*/
