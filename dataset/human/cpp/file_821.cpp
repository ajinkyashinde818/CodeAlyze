#include <bits/stdc++.h>
using namespace std;
const int maxn = 3030;
long long f[4][maxn<<2];
int main(){
	f[0][0] = 1;
	int a[3]; 
	for(int i = 0; i < 3; i++) cin >> a[i];
	int n; cin >> n;
	for(int i = 0; i < 3; i++){
		for(int k = 0; k*a[i] <= n; k++){
			for(int j = 0; j < maxn; j++){
				f[i+1][j+k*a[i]] += f[i][j];
			}
		}
	}
	cout << f[3][n] << endl;
	return 0;
}
