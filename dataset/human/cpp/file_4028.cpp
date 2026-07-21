#include <bits/stdc++.h>
using namespace std;

struct Dat{
	int x; double d;
	bool operator<(const Dat &oth) const {
		return d > oth.d;
	}
};

const double inf = 1e10;
int n, x[1010], y[1010], r[1010];
double c[1010][1010], md[1010];
priority_queue<Dat> pq;

int main(){
	scanf("%d%d%d%d%d", x, y, x + 1, y + 1, &n);
	x[n + 1] = x[1]; y[n + 1] = y[1];
	for(int i = 1; i <= n; i++) scanf("%d%d%d", x + i, y + i, r + i);
	for(int i = 0; i <= n; i++){
		for(int j = i + 1; j <= n + 1; j++){
			c[i][j] = c[j][i] = max(0.0, hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j]);
		}
	}
	fill(md + 1, md + n + 2, inf);
	pq.push({0, 0});
	while(!pq.empty()){
		Dat cur = pq.top(); pq.pop();
		for(int i = 0; i <= n + 1; i++){
			if(md[i] > cur.d + c[cur.x][i]){
				md[i] = cur.d + c[cur.x][i];
				pq.push({i, md[i]});
			}
		}
	}
	printf("%.12f\n", md[n + 1]);
}
