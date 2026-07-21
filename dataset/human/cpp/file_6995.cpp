/*
Arthor : Ender_zzm
E-mail zzm_ender_wiggin@outlook.com
Blog oi.ender-zzm.pro
*/
#include <bits/stdc++.h>
using namespace std;

inline int Isdigit(char c) {
	if (c < '0' || c > '9') return 0;
	return 1;
}
inline int readint(){
    register int x = 0, flag = 1;
    register char ch;
    while (!Isdigit(ch = getchar())) if (ch == '-') flag = -1;
    while (Isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
	return x * flag;
}

inline long long readlong() {
	register long long x = 0, flag = 1;
	register char ch;
	while (!Isdigit(ch = getchar())) if (ch == '-') flag = -1;
    while (Isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
	return x * flag;
}
template <class T>
inline void write(T x){
    if (x < 0)
        putchar('-'), x = -x;
    if(x >= 10) write(x / 10); 
    putchar(x % 10 + '0');
}

template<class T> inline bool Chkmax(T& x, const T& y) { return x < y ? x = y, true : false; }
template<class T> inline bool Chkmin(T& x, const T& y) { return x > y ? x = y, true : false; }

#define debug(x) cout << #x << " = " << x << endl;
#define For(i, x, y) for (int i = (x); i <= (y); i++) 
#define Rep(i, x, y) for (int i = (x); i >= (y); i--) 
#define ri readint
#define rl readlong

const int maxn = 2e5 + 30;
int n;
int a[maxn], b[maxn];
int cmp(int x, int y) {
	return x > y;
}
int main() {
	n = ri();
	for (int i = 1; i <= n; i++) {
		a[i] = ri();
	}
	for (int j = 1; j <= n; j++) {
		b[j] = ri();
	}
	sort(b + 1, b + 1 + n, cmp);
	int ok = 0, begin = n + 1, end = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == b[i]) {
			ok = 1;
			begin = min(begin, i);
			end = max(end, i);
		}
	}
	if (ok == 0) {
		puts("Yes");
		for (int i = 1; i<= n; i++) {
			printf("%d ", b[i]);
		}
		return 0;
	}
	if (begin - 1 + (n - end) < (end - begin + 1)) {
		puts("No");
		return 0;
	}
	int delta = end - begin + 1;
	int pos = begin;
	for (int i = 1; i < begin; i++) {
		if (b[i] == b[pos] || a[i] == b[pos]) continue;
		swap(b[i], b[pos]); delta--;
		pos++;
		if (delta == 0) break;
	}
	if (delta ==0) {
		puts("Yes"); 
		for (int i = 1; i<= n; i++) {
			printf("%d ", b[i]);
		}
		return 0;
	}
	for (int i = end + 1; i <= n; i++) {
		if (b[i] == b[pos] || a[i] == b[pos]) continue;
		swap(b[i], b[pos]);
		pos++, delta--;
		if (delta == 0) break;
	}
	if (delta) {
		cout << "No" << endl; return 0;
	}
	puts("Yes"); 
	for (int i = 1; i<= n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
