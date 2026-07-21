#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
using ull = unsigned long long;

int main(){
	int N;
	scanf("%d", &N);
	unsigned A[N], min = 1e9;
	ull ans = 0;
	bool fugou = false;
	for (int i = 0; i < N; ++i){
		int tmp;
		scanf("%d", &tmp);
		unsigned plus = abs(tmp);
		if(min > plus) min = plus;
		ans += plus;
		fugou ^= tmp < 0;
	}
	printf("%llu\n", ans - (fugou ? min << 1 : 0));
	return 0;
}
