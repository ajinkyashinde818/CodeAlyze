#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	double dN = N*2;
	int m = sqrt(dN);
	if(m*(m+1)>>1 != N){
		printf("No\n");
		return 0;
	}
	printf("Yes\n%d\n", m+1);
	int S[m][m];
	for (int i = 0; i < m; ++i) S[i][0] = i + 1;
	for (int i = 0; i < m - 1; ++i){
		for (int j = 0; j <= i; ++j)S[j][i+1] = S[i+1][j+1] = m + (i*(i+1)>>1) + j+1;
	}
	printf("%d", m);
	for (int i = 0; i < m; ++i) printf(" %d", i+1);
	printf("\n");
	for (int i = 0; i < m; ++i){
		printf("%d", m);
		for (int j = 0; j < m; ++j) printf(" %d", S[i][j]);
		printf("\n");
	}
	return 0;
}
