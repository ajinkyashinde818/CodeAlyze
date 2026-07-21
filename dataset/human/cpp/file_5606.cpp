#include <bits/stdc++.h>
using namespace std;

int main() {
	int		a,b,c,r,i,j,k,n,m,x,y,ans = 0;
	string	str;
	
	cin >> n >> r;
	
	
	if (n>=10) {
		ans = r;
	} else {
		ans = r + 100*(10-n);
	}
	cout << ans << endl;


}
