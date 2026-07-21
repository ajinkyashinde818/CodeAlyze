#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
int minimum(int a, int b) { return a < b ? a : b; }
int maximum(int a, int b) { return a > b ? a : b; }
const long long mod = 1000000007;
//const long long mod = 998244353;
int main() {
	int N, R;
	scanf("%d %d", &N, &R);
	printf("%d", R + 100 * maximum(10 - N, 0));
	return 0;
}
