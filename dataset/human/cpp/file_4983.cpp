#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;


int main() {
	
	int n, m;
	cin >> n >> m;
	if (n >= 10)cout << m;
	else cout << m + 100 * (10 - n);
}
