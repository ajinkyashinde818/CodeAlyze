#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			int rem = n-i*r-j*g;
			if(rem>=0 and rem%b==0) ans++;
		}

	}
	cout << ans << endl;
    return 0;
}
