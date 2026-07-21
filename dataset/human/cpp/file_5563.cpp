#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n, r; cin>>n>>r;
	if(n<10)cout<<r+(100*(10-n))<<'\n';
	else cout<<r<<'\n';
	return 0;
}
