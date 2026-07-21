#include <cstdio>
using namespace std;

constexpr int MOD = 1000000007;

int main() {
	int N;
	scanf("%d%*c", &N);
	bool S[N * 2];
	char c;
	for(int i = 0; i < N * 2; i++) {
		scanf("%c", &c);
		S[i] = (c == 'B');
	}

	long long ans = 1;
	int acc = 0;
	for(int i = 0; i < N * 2; i++) {
		if((acc & 1) ^ S[i]) {
			acc++;
		} else {
			if(acc == 0) {
				printf("0\n");
				return 0;
			}
			ans *= acc--;
			ans %= MOD;
		}
	}
	if(acc != 0) {
		printf("0\n");
		return 0;
	}

	for(int i = 2; i <= N; i++) {
		ans *= i;
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
