#include <bits/stdc++.h>
using namespace std;
int main() {
	int r, g, b, n; cin >> r >> g >> b >> n;
	int cnt = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if((n-g*i-b*j)>=0 && (n-g*i-b*j)%r==0){
				cnt++;
			}else{
				continue;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
