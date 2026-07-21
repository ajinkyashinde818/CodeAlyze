#include<bits/stdc++.h>
typedef long long ll;
inline ll read() {ll x = 0;char ch = getchar(), w = 1;while(ch < '0' || ch > '9') {
if(ch == '-') w = -1;ch = getchar();}while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();
}return x * w;}
void write(ll x) {if(x < 0) putchar('-'), x = -x;if(x > 9) write(x / 10);putchar(x % 10 + '0');}
inline void writeln(ll x) {write(x);puts("");}
using namespace std;

const int N = 5e5 + 666;
const ll mo = 1e9 + 7;
char s[N];
int n;
int v[N];
int main() {
	n = read();
	scanf("%s", s + 1);
	n *= 2;
	if(s[1] == 'W' || s[n] == 'W') {
		puts("0");
		return 0;
	}
	int d = 1;
	for(int i = 2; i <= n; ++i) {
		if(s[i] == 'W') {
			if(d & 1) v[i] = 0, ++d;
			else v[i] = 1, --d;
		} else {
			if(d & 1) v[i] = 1, --d;
			else v[i] = 0, ++d;
		}
	}
	if(d) {
		puts("0");
		return 0;
	}
/*	for(int i = 1; i <= n; ++i)
		printf("%d ", v[i]);*/
	d = 0;
	ll res = 1;
	for(int i = 1; i <= n / 2; ++i) res = res * i % mo;
	for(int i = 1; i <= n; ++i) {
		if(v[i] == 0) ++d;
		else res = res * d % mo, --d;
	}
	writeln(res);
	return 0;
}
