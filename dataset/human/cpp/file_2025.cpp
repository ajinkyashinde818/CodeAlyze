#include <iostream>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 5;

int n;
int num[MAXN], cnt;
LL ans;
bool hav0 = false;

int main() {
	ios :: sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (num[i] < 0) cnt++;
		if (num[i] == 0) hav0 = true;
	}
	if (cnt % 2 == 0) {
	    for (int i = 1; i <= n; i++) {
		    ans += (num[i] < 0 ? -num[i] : num[i]); 
		}
		cout << ans << endl;
		return 0;
	} else if (hav0) {
		for (int i = 1; i <= n; i++) {
			ans += (num[i] < 0 ? -num[i] : num[i]);
		}
		cout << ans << endl;
		return 0;
	} else {
		int num1 = -1e9, pos1 = 0, num2 = 1e9, pos2 = 0;
		for (int i = 1; i <= n; i++) {
			if (num[i] < 0 && num[i] > num1) num1 = num[i], pos1 = i;
			if (num[i] > 0 && num[i] < num2) num2 = num[i], pos2 = i;
		}
		if (num2 > -num1) {
			for (int i = 1; i <= n; i++) {
				if (i == pos1) ans += num[i];
				else ans += (num[i] < 0 ? -num[i] : num[i]);
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (i == pos2) ans += -num[i];
				else ans += (num[i] < 0 ? -num[i] : num[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
