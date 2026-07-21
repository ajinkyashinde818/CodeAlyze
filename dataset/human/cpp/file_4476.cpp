#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<functional>
#include<stack>
#include<list>
#include<set>
#include<deque>
#include<climits>
using namespace std;

typedef long long ll;

int main(){
	int N, M, ans[100];
	cin >> N >> M;
	ans[0] = M;
	for(int i = 1; i < (N-1)/2; i++) ans[i] = M;
	for(int i = (N-1)/2; i < N; i++) ans[i] = 0;

	printf("%d", ans[0]);
	for(int i = 1; i < N; i++) printf(" %d", ans[i]);
	puts("");
	return 0;
}
