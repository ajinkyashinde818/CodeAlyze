#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cassert>
#include <bitset>
#include <stack> 

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 998244353 
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

vector <int> ans[100000];
int n;

int main() {
	cin >> n;
	int num = sqrt(n * 2);
	if (num * (num + 1) != 2 * n) {
		cout << "No" << endl;
		return 0;
	}
	int cc = num;
	for (int i = 0; i < num; i++) ans[0].push_back(i);
	for (int i = 1; i < num + 1; i++) {
		for (int j = 0; j < i; j++) ans[i].push_back(ans[j][i - 1]);
		for (int j = i; j < num; j++) ans[i].push_back(cc++);
	}
	cout << "Yes" << endl;
	cout << num + 1 << endl;
	for (int i = 0; i < num + 1; i++) {
		cout << num << " ";
		for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] + 1 << " ";
		cout << endl;
	}
	return 0;
}
