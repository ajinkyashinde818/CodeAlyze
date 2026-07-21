#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,r;
	cin>>n>>r;
	if(n>=10){
		cout<<r<<endl;
	}else{
		cout<<r+100*(10-n)<<endl;
	}
    return 0;
}
