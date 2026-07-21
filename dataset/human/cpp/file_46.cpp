#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void) {

	// TODO: submit前にprintf-debugの削除確認！
	int r, g, b, n;
	//long long N, M;
	//double d, e;
	//string s, t;
	//vector<int> v;
	//vector<pair<int, int>> pl;

	//while() {}
	//for(int i=0; i<N; i++) {}
	
	cin >> r >> g >> b >> n;
	int ans = 0;

	for(int ri=0; ri*r<=n; ri++) {
		int rNum = ri * r;
		for(int gi=0; gi*g+rNum<=n; gi++) {
			int gNum = gi * g;
			int left = n - (rNum + gNum);
			int mod = left % b;
			if(mod == 0) ans++;
		}
	}

	cout << ans;
	// cout << "[deb: val ]" << val <<endl;
	return 0;
}
