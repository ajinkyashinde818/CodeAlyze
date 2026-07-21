#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstdio>

using namespace std;
/*
int find(int x, vector<int> &p) {
if (p[x] == x)return x;
return p[x] = find(p[x], p);
}

void uni(int x, int y, vector<int> &p) {
x = find(x, p);
y = find(y, p);
p[x] = y;
}

int same(int x, int y, vector<int> p) {
if (find(x, p) == find(y, p))return 1;
return 0;
}
*/

//long long a[1002];

int R, G, B;
long long ans = 0;
const int MAX_N = 3001;

int memo[MAX_N][3];

int fn(int n, int mark) {
	if (n == 0) {
		return 1;
	}
	if (mark != 0 && memo[n][mark-1] != -1) return memo[n][mark-1];
	int tmp1 = 0, tmp2 = 0, tmp3 = 0;
	if (n - R >= 0 && mark < 2) tmp1 = memo[n - R][0] = fn(n - R, 1);
	if (n - G >= 0 && mark < 3) tmp2 = memo[n - G][1] = fn(n - G, 2);
	if (n - B >= 0 && mark < 4) tmp3 = memo[n - B][2] = fn(n - B, 3);
	if (n - R < 0 && n - G < 0 && n - B < 0) return 0;
	//return memo[n - R][0] + memo[n - G][1] + memo[n - B][2];
	return tmp1 + tmp2 + tmp3;
}

int main()
{
	for (int i = 0; i < MAX_N; ++i) {
		for (int j = 0; j < 3; j++) {
			memo[i][j] = -1;
		}
	}
	long long N, K, cnt = 0, tmp;
	cin >> R >> G >> B >> N;
	cout << fn(N, 0) << endl;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < N; i++) {
			//cout << memo[i][j] << endl;
		}
		//cout << endl;
	}
	char qq;
	cin >> qq;
	return 0;
}
