#include <bits/stdc++.h>

using namespace std;

int R,G,B,N;
typedef long long LL;

int main() {
	scanf("%d%d%d%d",&R,&G,&B,&N);
	LL ans = 0;
	for (int r=0;r<=3000;r++) {
		for (int g=0;g<=3000;g++) {
			if (N - r*R - g*G >= 0 && (N - r*R - g*G) % B == 0) {
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
