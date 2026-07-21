#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
	int q, w, e, r;
	int dap = 0;
	scanf("%d %d %d %d", &q, &w, &e, &r);
	for (int i = 0; i <= r; i++) {
		for (int y = 0; y <= r; y++) {
			int x = q * i + y * w;
			if (x > r)continue;
			if ((r - x) % e == 0)dap++;
		}
	}
	printf("%d\n", dap);
}
