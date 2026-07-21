#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>
 
int main(void){
	int n;
	std::cin >> n;
	std::vector<int64_t> a(n);
	for(int i=0;i<n;i++)std::cin >> a[i];
	//i-1番目までの数の和の最大値
	std::vector<int64_t> dp(n+1), dp_inv(n+1);
	dp[0] = 0;
	dp_inv[0] = 0;
	for(int i=0;i<n;i++){
		//i, i+1の符号を反転させない
		if(i == 0){
			dp[i+1] = dp[i] + a[i];
		}else{
			dp[i+1] = std::max(dp[i] + a[i], dp_inv[i] - a[i]);
		}
		//i, i+1の符号を反転させる
		if(i == 0){
			dp_inv[i+1] = dp[i] - a[i];
		}
		else{
			dp_inv[i+1] = std::max(dp[i] - a[i], dp_inv[i] + a[i]);
		}
	}
	std::cout << dp[n] << std::endl;
}
