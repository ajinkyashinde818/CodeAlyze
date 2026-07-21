#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<int> l,r;
long long ans = 1,mod = 1000000007;
int main(){
	int i,n;
	cin >> n >> s;
	for(i=0;i<2*n;i++){
		int x = l.size() - r.size();
		if(x<0){
			cout << 0 << endl;
			return 0;
		}
		if(x&1){
			if(s[i]=='W') l.push_back(i);
			else r.push_back(i);
		}else{
			if(s[i]=='W') r.push_back(i);
			else l.push_back(i);
		}
	}
	if(l.size()!=n || r.size()!=n){
		cout << 0 << endl;
		return 0;
	}
	int z = n;
	long long cnt = 0;
	for(i=n - 1;i>=0;i--){
		while(z>0 && r[z - 1]>l[i]){
			cnt++; z--;
		}
		(ans *= cnt) %= mod;
		cnt--;
	}
	for(i=1;i<=n;i++){
		(ans *= i) %= mod;
	}
	cout << ans << endl;
}
