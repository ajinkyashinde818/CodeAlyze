#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio (false);
	cout << fixed;
	cout.precision(10);
	if(fopen("joke.in", "r")){
		freopen ("joke.in","r",stdin);
		freopen ("joke.out","w",stdout);
	}

	int n;
	cin >> n;
	vector<long long> b(n);	
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}

	int cnt_zero = 0;
	int cnt_neg = 0;
	long long tot = 0;
	long long min_abs = 1e18;
	for(int i = 0; i < n; ++i){
		if(b[i] == 0) cnt_zero++;
		if(b[i] < 0){
			cnt_neg++;
		} 
		tot += abs(b[i]);
		min_abs = min(min_abs, abs(b[i]));
	}

	long long res = 0;
	if( cnt_zero > 0 || (cnt_neg % 2 == 0) ){
		res = tot;
	}else{
		res = tot - 2 * min_abs;
	}

	cout << res;
    return 0;
}
