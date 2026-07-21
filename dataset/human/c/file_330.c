// AOJ 2656 Taps
// 2018.4.6 bal4u

#include <stdio.h>
#include <string.h>
#include <math.h>

//#define getchar_unlocked()  getchar()
int in()
{
	int n = 0, c = getchar_unlocked();
	do n = 10*n + (c & 0xf), c = getchar_unlocked(); while (c >= '0');
	return n;
}

#define EPS 1e-6
#define EQ(a,b)  (fabs((a)-(b))<EPS)

int T, D, ta, tb, da, db;

int ok(int a, int b)
{
	int t = a*da + b*db;
	return t >= 1 && t <= D;
}

double calc2()
{
	int a, b;
	double s, t, ans;

	s = (double)(ta-tb)/(ta-T) * db;
	ans = 100;
	for (b = 1; ; b++) {
		t = b*s;
		if (!EQ(t, 1) && t <= 1) continue;
		if (!EQ(t, D) && t >= D) break;
		t = (double)(T-tb)*db*b / ((ta-T)*da);
		a = (int)t;
		if (a < 0) continue;
		if (!ok(a, b)) continue;
		t = ta*a*da + tb*b*db, t /= a*da+b*db, t = fabs(T-t);
		if (t < ans) ans = t;
		if (!ok(++a, b)) continue;
		t = ta*a*da + tb*b*db, t /= a*da+b*db, t = fabs(T-t);
		if (t < ans) ans = t;
	}
	return ans;
}

double calc()
{
	int x;
	double t, ans;

	if (ta == tb) return fabs(T-ta);
	if (ta == T || tb == T) return 0;
	t = ta; if (t < tb) t = tb;
	if (T > t) return T-t;
	t = ta; if (t > tb) t = tb;
	if (T < t) return t-T;
	ans = fabs(T-ta), t = fabs(T-tb);
	if (t < ans) ans = t;

	t = calc2();
	if (t < ans) ans = t;
	x = ta, ta = tb, tb = x;
	x = da, da = db, db = x;
	t = calc2();
	if (t < ans) ans = t;
	return ans;
}

int main()
{
	T = in(), D = in();
	ta = in(), tb = in();
	da = in(), db = in();
	printf("%.10lf\n", calc());
	return 0;
}
