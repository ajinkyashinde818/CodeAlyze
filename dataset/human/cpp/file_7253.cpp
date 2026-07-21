#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;

int main(){
	long long int n,s=0,rsum;
	cin >> n;
	vector<long long int>a(n);
	for(auto& v : a){
		cin >> v;
		s += v;
	}
	rsum = s;
	
	long long int out = LLONG_MAX;
	for(int i = 0; i < n - 1; ++i){
		rsum -= a[i];
		if(abs(s - rsum - rsum) < out){
			out = abs(s - rsum - rsum);
		}
	}

	cout << out << endl;
	return 0;
}
