#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){
	int r, g, b, n, ans = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i < 3010; i++) {
		for (int j = 0; j < 3010; j++) {
			int num = n - (i * r + j * g);
			if(num >= 0 && num%b==0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
