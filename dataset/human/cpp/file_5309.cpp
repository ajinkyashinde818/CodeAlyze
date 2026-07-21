#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 200000 + 5;

int main() {
	int n,k;
	cin >> n >> k;
	if(n >= 10)
		cout << k << endl;
	else
		cout << k + 100 * (10-n) << endl;
	return 0; 
}
