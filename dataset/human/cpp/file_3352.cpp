#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;

int main(){
	int n;
	cin >> n;
	vector<lli> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	lli sum=0;
	bool even=true;
	lli absmin=1e18;
	for(int i=0; i<n; i++){
		sum += abs(a[i]);
		absmin = min(absmin, abs(a[i]));
		if(a[i] < 0){
			even = !even;
		}
	}
	if(even){
		cout << sum << endl;
	}else{
		cout << sum -2*absmin << endl;
	}
    return 0;
}
