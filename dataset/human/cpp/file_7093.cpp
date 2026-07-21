#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;
int cnta[maxn], cntb[maxn], a, ya[maxn];

struct Zip {
	int id, num;
	
	Zip(int id=0, int num=0) : id(id), num(num) {}
	
	bool operator<(Zip op) {
		return num > op.num;
	}
};

vector<Zip> za;
queue<Zip> Q;
vector<int> c;

int main() {
	int n;
	cin >> n;
	memset(cnta, 0, sizeof(cnta));
	memset(cntb, 0, sizeof(cntb));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		cnta[a]++;
		ya[i] = a;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		cntb[a]++;
	}
	bool flag = true;
	for (int i = 1; i <= n; ++i) {
		if (cnta[i]) za.push_back(Zip(i, cnta[i]));
		if (cntb[i]) Q.push(Zip(i, cntb[i]));
		if (cnta[i] + cntb[i] > n) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		printf("No\n");
		return 0;
	}
	Zip x = Q.front(); Q.pop();
	for (int i = 0; i < za.size(); ++i) {
		if (x.id == za[i].id || x.num == 0) {
			if (x.num) Q.push(x);
			x = Q.front(); Q.pop();
		}
		while (za[i].num) {
			if (x.id == za[i].id) {
				Q.push(x);
				x = Q.front(); Q.pop();
			}
			za[i].num--;
			x.num--;
			c.push_back(x.id);
			if (x.num == 0) {
				x = Q.front();
				Q.pop();
			}
		}
	}
	printf("Yes\n");
	for (int L = 0, R = n-1; L < R; --R) {
		if (ya[R] == c[R]) {
			while (c[L] == ya[R]) L++;
			swap(c[L], c[R]);
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", c[i]);
	printf("\n");
	return 0;
}
