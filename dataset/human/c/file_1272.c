#include <stdio.h>

const long long mod = 1000000007;

struct mat {
	int a[3][3];

	mat operator -(mat t) {
		mat r;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++){
			r.a[i][j] = (a[i][j] + mod - t.a[i][j]) % mod;
		}
		return r;
	}

	mat operator *(mat t){
		mat r;
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++){
			r.a[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				r.a[i][j] = (r.a[i][j] + (long long)a[i][k] * t.a[k][j]) % mod;
			}
		}
		return r;
	}

	int get(){
		return (a[2][0] * 5ll + a[2][1]) % mod;
	}
};

int N, M, X[100100],D[100100];

int main()
{
	mat base[32];
	base[0] = mat{ 4,mod - 2,1,1,0,0,0,1,0 };
	for (int i=1;i<32;i++) base[i] = base[i-1] * base[i-1];

	scanf("%d %d", &N, &M);
	for (int t = 1; t <= M; t++) scanf("%d", &X[t]);
	X[M + 1] = N;

	mat sum = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	mat idt = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	mat all = idt;

	for (int i = 1; i <= M + 1; i++) {
		mat now = idt;
		for (int j=0,x=X[i]-X[i-1];x;j++,x/=2) if (x & 1) now = now * base[j];
		sum = sum * now;
		all = all * now;
		D[i] = (all - sum).get();
		for (int k = 0; k < 3; k++) sum.a[k][k] = (sum.a[k][k] + D[i]) % mod;
	}

	printf("%d\n", D[M+1]);
	return 0;
}
