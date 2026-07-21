#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,r;
	cin >> n >> r;
	if(n>=10) cout << r << endl;
	else{
		n=100*(10-n);
		cout << r+n << endl;
	}
	return 0;
}
