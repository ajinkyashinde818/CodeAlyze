#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;



int main() {
	int n;
	cin >> n;
	
	ll min = 1000000000;
	int cnt_nega = 0;
	ll sum = 0;
	
	for (int i = 0; i < n;i++) {
		int a;
		cin >> a;

		if (a < 0) {
			cnt_nega++;
		}

		int abs_a = abs(a);
		sum += abs_a;
		if (abs_a < min) {
			min = abs_a;
		}
		

	}

	if (cnt_nega % 2 != 0) {
		sum -= 2 * min;
	}
	cout << sum;
	
}
