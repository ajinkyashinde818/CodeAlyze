#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;


int main(void) {
	int R, G, B, N;
	int ans;
	scanf("%d %d %d %d", &R, &G, &B, &N);
	ans = 0;

	for (int i = 0; i*R <= N; i++) {
		for (int j = 0; i*R + j * G <= N; j++) {
			if ((N - i * R - j * G) % B == 0) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);

}
