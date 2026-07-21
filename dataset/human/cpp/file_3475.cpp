#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007

int n;
long long int a[100001];
long long int result[100001][2];
long long int INIT = (long long int)mod * 100000;

long long int solve(int i, int j)
{
	if(i == n - 1) return a[n - 1] * (long long int)pow(-1, j);
	if(result[i][j] != INIT) return result[i][j];
	return result[i][j] = max(a[i] * (long long int)pow(-1, j) + solve(i + 1, 0), a[i] * (long long int)pow(-1, j + 1) + solve(i + 1, 1));
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		result[i][0] = result[i][1] = INIT;
	}
	cout << solve(0, 0) << endl;
}
