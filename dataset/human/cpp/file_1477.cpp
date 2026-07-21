#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, k;
vector<int> S[450];

int main(){
	getint(N), k = (int)sqrt((N << 3) + 1.0) + 1 >> 1;
	if(k * (k - 1) != N << 1) return puts("No"), 0;
	for(register int i = 1, cur = 0; i <= k; i++)
		for(register int j = i + 1; j <= k; j++)
			S[i].push_back(++cur), S[j].push_back(cur);
	puts("Yes"), printf("%d\n", k);
	for(register int i = 1, siz; i <= k; i++, puts("")){
		printf("%d ", siz = S[i].size());
		for(register int j = 0; j < siz; j++) printf("%d ", S[i][j]);
	}
	return 0;
}
