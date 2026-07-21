#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

inline char gc()
{
	static const int L = 23333;
	static char sxd[L], *sss = sxd, *ttt = sxd;
	if (sss == ttt)
	{
		ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
		if (sss == ttt) return EOF;
	}
	return *sss++;
}

#ifdef ___my_computer
#define gc getchar
#endif

#define dd c = gc()
template <class T>
inline bool read(T& x)
{
	x = 0;
	register char dd;
	bool flag = false;
	for (; !isdigit(c); dd)
	{
		if(c == '-') flag = true;
		else if(c == EOF) return false;
	}
	for (; isdigit(c); dd)
		x = (x << 1) + (x << 3) + (c ^ 48);
	if (flag) x = -x;
	return true;
}
#undef dd

template <class T>
inline void write(T x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	if (x < 0)
		putchar('-'), x = -x;
	int buf[20];
	*buf = 0;
	while (x)
	{
		buf[++(*buf)] = x % 10;
		x /= 10;
	}
	while (*buf)
		putchar(buf[(*buf)--] | 48);
}

template <class T>
inline void writeln(T x)
{
	write(x);
	puts("");
}

template <class T>
inline void writesp(T x)
{
	write(x);
	putchar(' ');
}

template <typename _EuclideanRingElement>
_EuclideanRingElement
gcd(_EuclideanRingElement __m, _EuclideanRingElement __n)
{
	while (__n)
	{
		_EuclideanRingElement __t = __m % __n;
		__m = __n;
		__n = __t;
	}
	return __m;
}

template <typename _EuclideanRingElement>
_EuclideanRingElement
lcm(_EuclideanRingElement __m, _EuclideanRingElement __n)
{
	return __m * __n / gcd(__m, __n);
}

const int maxn = 100005;

int n;
int fa[maxn];
int a[maxn], b[maxn];
int ta[maxn], tb[maxn];
map<int, int> ls;

inline int getfa(int x)
{
	return fa[x] == x ? x : (fa[x] = getfa(fa[x]));
}

int main()
{
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	n++;
	for (int i = 1; i < n; ++i)
	{
		read(a[i]);
		a[n] ^= a[i];
	}
	for (int i = 1; i < n; ++i)
	{
		read(b[i]);
		b[n] ^= b[i];
	}
	for (int i = 1; i <= n; ++i)
		ta[i] = a[i], tb[i] = b[i];
//	cout << a[n] << ' ' << b[n] << endl;
	sort(ta + 1, ta + n + 1);
	sort(tb + 1, tb + n + 1);
	for (int i = 1; i < n; ++i)
	{
		if (ta[i] != tb[i])
		{
			puts("-1");
			return 0;
		}
		if (a[i] != b[i])
			ls[a[i]]++, ls[b[i]]++;
	}
	ls[a[n]]++, ls[b[n]]++;
	int siz = 0;
	for (map<int, int>::iterator it = ls.begin(); it != ls.end(); ++it)
		it->second = ++siz;
	for (int i = 1; i <= siz; ++i)
		fa[i] = i;
	int ans = 0;
//	ofstream fout("deb.out");
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != b[i])
		{
			int fax = getfa(ls[a[i]]);
			int fay = getfa(ls[b[i]]);
			if (fax != fay)
				fa[fax] = fay;
//			fout << ls[a[i]] << ' ' << ls[b[i]] << '\n';
			if (i != n)
				ans++;
		}
	}
//	fout.close();
	for (int i = 1; i <= siz; ++i)
	{
		ans += (fa[i] == i);
//		if (fa[i] == i)
//			cout << i << endl;
	}
	write(max(0, ans - 1));
	return 0;
}
