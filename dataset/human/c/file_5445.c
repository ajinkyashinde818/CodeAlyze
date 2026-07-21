// Aizu Vol-5 0594: Super Metropolis
// 2017.8.31 bal4u@uu

#include <stdio.h>

#define abs(x) ((x)>=0?(x):-(x))
#define max(x,y) ((x)>=(y)?(x):(y))

int shortpath(int xf, int yf, int xt, int yt)
{
	if ((xt >= xf && yt <= yf) || (xt <= xf && yt >= yf)) return abs(xt-xf)+abs(yt-yf);
	return max(abs(xt-xf), abs(yt-yf)); 
}

int main()
{
	int w, h, n, x1, y1, x2, y2, ans;

	scanf("%d%d%d%d%d", &w, &h, &n, &x1, &y1);
	for (ans = 0, n--; n-- > 0; x1 = x2, y1 = y2) {
		scanf("%d%d", &x2, &y2);
		ans += shortpath(x1, y1, x2, y2);
	}
	printf("%d\n", ans);
	return 0;
}
