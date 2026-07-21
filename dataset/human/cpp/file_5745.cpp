#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, cnt;
long long L;
struct Trie {
	int ch[2], dep;
}T[301000];
char p[101000];
void Put(int a, char *key) {
	if (!(*key))return;
	int c = *key - '0';
	if (!T[a].ch[c]) {
		T[a].ch[c] = ++cnt;
		T[cnt].dep = T[a].dep + 1;
	}
	Put(T[a].ch[c], key + 1);
}
long long Get(long long a) {
	if (!a)return 0;
	if (a & 1)return 1;
	return Get(a >> 1) << 1;
}
int main() {
	int i, root = 1;
	scanf("%d%lld", &n, &L);
	cnt = 1;
	for (i = 0; i < n; i++) {
		scanf("%s", p);
		Put(root, p);
	}
	long long res = 0;
	for (i = 1; i <= cnt; i++) {
		if ((!T[i].ch[0]) != (!T[i].ch[1])) {
			res ^= Get(L - T[i].dep);
		}
	}
	if (res)puts("Alice");
	else puts("Bob");
}
