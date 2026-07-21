#include <stdio.h>
int main() {
	int k, s, ans = 0;
	scanf("%d%d", &k, &s);
	for(int x=0;x<=k && x<=s;++x) {
		for(int y=0;y<=k && y+x<=s;++y) {
			if(s-x-y<=k) ++ans;
		}
	}
	printf("%d\n", ans);
}
