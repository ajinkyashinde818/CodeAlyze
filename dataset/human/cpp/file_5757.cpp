#include<bits/stdc++.h>
using namespace std;

int n, ch[100100][2], cnt; 
long long L, ans;
char s[100100];

void Slve(int x, long long L) {
	if(ch[x][0]) Slve(ch[x][0], L - 1);
	if(ch[x][1]) Slve(ch[x][1], L - 1);
	if((!ch[x][0]) ^ (!ch[x][1])) ans ^= L & -L;
}

int main(void) {
	scanf("%d%lld", &n, &L);
	cnt = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s);
		int m = strlen(s), p = 1;
		for(int i = 0; i < m; i++) {
			int idx = s[i] - '0';
			if(!ch[p][idx]) ch[p][idx] = ++cnt;
			p = ch[p][idx];
		}
	}
	Slve(1, L);
	puts(ans ? "Alice" : "Bob");
	return 0;
}
