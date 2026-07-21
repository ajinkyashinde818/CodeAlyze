#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;

int main(){
	int n,r;
	cin >> n >> r; 
	if(n >= 10) cout << r << endl;
	else cout << r + 100*(10-n) << endl;
	return 0;
}
