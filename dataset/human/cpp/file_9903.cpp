#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
using namespace std;


int main() {
	//cout << fixed << setprecision(10);
	long long int n, m, k, res = 1, a, b, ok[40] = {};
	string str;
	cin >> n>>str;
	for (int i = 0; i < n; i++) {
		ok[str[i] - 'a']++;
	}
	for (int i = 0; i < 30; i++) {
		res*=ok[i]+1;
		res %= 1000000007;
	}
	cout << (res-1)%1000000007;


	

}
