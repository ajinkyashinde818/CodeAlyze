#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> ans(n, m);
	for(int i=0; i<n; i++){
		if(n%2 == 0){
			if(i <= n/2) ans[i] = 0;
		}else{
			if(i < n/2 +1) ans[i] = 0;
		}
	}
	for(int i=0; i<n-1; i++) cout << ans[i] << " ";
	cout << ans[n-1] << endl;
    return 0;
}
