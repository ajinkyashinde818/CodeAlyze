#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n, m;
	cin >> n >> m;
	
	vector<string> a(n), b(m);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	
	for(int px = 0; px < n; ++px) {
		for(int py = 0; py < n; ++py) {
			int cnt = 0;
			
			for(int tx = 0; tx < m; ++tx) {
				for(int ty = 0; ty < m; ++ty) {
					if( px + m - 1 >= n || py + m - 1 >= n ) continue;
					
					if( a[px + tx][py + ty] == b[tx][ty] ) {
						cnt++;
					}									
				}
			}
			
			if( cnt == m * m ) {
				cout << "Yes" << endl;
				return 0;
			}
		}			
	}
	
	cout << "No" << endl;
	
	return 0;
}
