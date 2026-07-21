#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double w[1010][1010], D[1010];
bool vis[1010];
struct point {
	long long x, y;
	point operator -(const point &p)const {
		return { x - p.x,y - p.y };
	}
	double SZ() {
		return sqrt(x*x + y*y);
	}
}P[1010];
long long R[1010];
int n;
void Input(point &a) {
	scanf("%lld%lld", &a.x, &a.y);
}
int main() {
	int i, j;
	Input(P[0]);
	Input(P[1]);
	scanf("%d", &n);
	for (i = 2; i <= n + 1; i++) {
		Input(P[i]);
		scanf("%lld", &R[i]);
	}
	n++;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			double t = (P[j] - P[i]).SZ() - R[i] - R[j];
			w[i][j] = max(0.0, t);
		}
	}
	for (i = 1; i <= n; i++)D[i] = 1e18;
	while (1) {
		double Mn = 1e18;
		int pv = -1;
		for (i = 0; i <= n; i++) {
			if (!vis[i] && Mn > D[i]) {
				Mn = D[i];
				pv = i;
			}
		}
		if (pv == -1)break;
		vis[pv] = true;
		for (i = 0; i <= n; i++) {
			D[i] = min(D[i], D[pv] + w[pv][i]);
		}
	}
	printf("%.15f\n", D[1]);
}
