#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;


int main() {
	int n;
	cin >> n;
	
	vector<ll> sum(n + 1);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		sum[i + 1] = sum[i] + a;

		
		
	}

	
	ll min = 1000000000000000;
	ll sumAll = sum[n];

	
	for (int i = 1; i < n; i++) {
		ll dif = abs(sumAll - (2 * sum[i]));
		
		if (dif < min) {
			min = dif;
		}
	}
	
	cout << min << endl;
	

}
