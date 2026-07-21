#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;
 
int N;
vector<int> S[1000];
 
int main()
{
	scanf("%d", &N);
 
	int a = -1;
	for (int i = 1; i <= 1000; ++i) {
		if (i * (i - 1) / 2 == N) {
			a = i;
			break;
		}
	}
	if (a == -1) {
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d\n", a);
 
	int idx = 1;
	for (int i = 0; i < a; ++i) {
		for (int j = i + 1; j < a; ++j) {
			S[i].push_back(idx);
			S[j].push_back(idx++);
		}
	}
	for (int i = 0; i < a; ++i) {
		printf("%d", S[i].size());
		for (int j : S[i]) printf(" %d", j);
		puts("");
	}
 
	return 0;
}
