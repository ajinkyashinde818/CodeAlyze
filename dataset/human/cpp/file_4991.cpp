#include <stdio.h>
#include <algorithm>
using namespace std;
using ll = long long;

int n, r;
int main() {
	scanf("%d %d", &n, &r);
	if (10 <= n)
		printf("%d\n", r);
	else
		printf("%d\n", r + 100 * (10 - n));
}
