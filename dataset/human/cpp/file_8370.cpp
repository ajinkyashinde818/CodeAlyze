#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	auto a = vector<string>(n);
	auto b = vector<string>(m);
	for(auto& x : a) cin >> x;
	for(auto& y : b) cin >> y;
	int ans = false;
	for(auto i = 0; i < n - m + 1; ++i){
		for(auto j = 0; j < n - m + 1; ++j){
			bool fit = true;
			for(auto k = 0; k < m; ++k){
				if(b[k] != a[i + k].substr(j, m)){
					fit = false;
					break;
				}
			}
			if(fit){
				ans = true;
				break;
			}
		}
		if(ans) break;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
