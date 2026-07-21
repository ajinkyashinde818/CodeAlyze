#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,r; cin>>n>>r;
	int x;
	if (n<10) cout<<r+100*(10-n);
	else cout<<r;
	return 0;
}
