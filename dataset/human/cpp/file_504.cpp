#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
static const int mod = 1e9;
using namespace std;

int main() {
	int r, g, b, n;
	int count = 0;
	cin >> r >> g >> b >> n;
	for (int i = 0; i <= n / r + 1; ++i) {
		for (int j = 0; j <= n / g + 1; ++j) {
			if((n-r*i-g*j)/b>=0&&(n-r*i-g*j)%b==0)++count;
		}
	}
	cout << count << endl;
	return 0;
}
