#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main() {
	int x, y, z,k;
	int s, ans;
	scanf("%d %d %d %d", &x, &y,&z,&s);
	ans = 0;
	f(i, 3010) {
		f(j, 3010) {
			k = s;
			k -= (i * x);
			k -= (j*y);
			if (k >= 0) {
				if (k%z == 0)ans++;
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}
