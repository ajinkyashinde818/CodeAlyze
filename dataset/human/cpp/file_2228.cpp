#include <iostream>
#include <vector>
#include <utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<list>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v.at(i);
	}                              
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (v.at(i) < 0) {
			v.at(i) *= -1;
			count++;
		}
	}
	int64_t sum = 0;
	for (int i = 0; i < n; i++) {
			sum += v.at(i);
	}
	int a = v.at(0);
	for (int i = 0; i < n; i++) {
		a = min(v.at(i), a);
	}
    if ((count) % 2 == 0) {
			cout << sum << endl;
	}
	else {
			cout << sum - (2*a) << endl;
	}
		return 0;
}
