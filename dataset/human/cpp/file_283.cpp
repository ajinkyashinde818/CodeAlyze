#include <iostream>
using namespace std;

typedef long long ll;

int main(){
	int r[3],n;
	cin >> r[0] >> r[1] >> r[2] >> n;
	
	ll dp[3002] = {};
	dp[0] = 1;
	for(int i = 0 ; i < 3 ; i ++){
		for(int j = 0 ; j+r[i] < 3002 ; j ++){
			dp[j+r[i]] += dp[j];
		}
	}
	cout << dp[n] << endl;
}
