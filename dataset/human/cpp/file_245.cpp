#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	for(int i=0;i<3001;i++){
		for (int j=0;j<3001;j++){
			int k = n - i*r - j*g;
			if(k>=0&&(k%b==0))ans++;
		}
	}
	cout << ans << endl;
}
