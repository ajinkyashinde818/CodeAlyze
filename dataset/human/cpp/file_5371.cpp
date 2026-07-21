#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<utility>
#include<iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, r;
	cin >> n >> r;
	if (n < 10) cout << r + 100 * (10 - n);
	else cout << r;
}
