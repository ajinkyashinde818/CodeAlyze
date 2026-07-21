#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<60)

int n, a[200001], sum[200001];
signed main(){

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n-1; i++){
		a[i + 1] += a[i];
	}

	int r = INF;
	for (int i = 0; i <= n - 2; i++){
		int c = abs(a[i] * 2 - a[n-1]);
		if (c < r) r = c;
	}

	cout << r << endl;


	return 0;
}
