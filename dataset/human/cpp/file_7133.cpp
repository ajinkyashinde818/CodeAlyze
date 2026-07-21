#include <bits/stdc++.h>
using namespace std;
vector<long long> pre;
int main(){
	long long int n, read, mini = LONG_LONG_MAX;
	cin >> n >> read;
	pre.push_back(read);
	for(int i = 1; i < n; ++i){
		cin >> read;
		pre.push_back(read + pre.back());
	}
	for(int i = 0; i < n-1; ++i){
		long long a = pre[i], b = pre[n-1] - pre[i];
		mini = min(abs(a - b), mini);
	}
	cout << mini << '\n';
	return 0;
}
