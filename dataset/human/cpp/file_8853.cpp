#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <string>
using namespace std;

const int qq = 1e2 + 10;
int num[qq];
int n, m, k;
char a[qq][qq], b[qq][qq];
bool judge(int x, int y){
	for(int i = x - m + 1, c = 1; i <= x; ++i, c++)
		for(int j = y - m + 1, d = 1; j <= y; ++j, d++)
			if(a[i][j] != b[c][d])	return false;
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for(int i = 1; i <= m; ++i)
		scanf("%s", b[i] + 1);
	for(int i = m; i <= n; ++i){
		for(int j = m; j <= n; ++j)
			if(judge(i, j)){
				puts("Yes");
				return 0;
			}
	}
	puts("No");
	return 0;
}
