#include <stdio.h>

int N; long long C,X[100100],V[100100],L[3][100100],R[3][100100];

int main()
{
	scanf ("%d %lld",&N,&C);
	for (int i=1;i<=N;i++) scanf ("%lld %lld",&X[i],&V[i]);

	long long s = 0;
	for (int i=1;i<=N;i++){
		s += V[i];
		for (int k=1;k<=2;k++){
			long long n = s - X[i] * k;
			L[k][i] = L[k][i-1];
			if (L[k][i] < n)
				L[k][i] = n;
		}
	}

	long long t = 0;
	for (int i=N;i>=1;i--){
		t += V[i];
		for (int k=1;k<=2;k++){
			long long n = t - (C - X[i]) * k;
			R[k][i] = R[k][i+1];
			if (R[k][i] < n)
				R[k][i] = n;
		}
	}

	long long ans = 0;
	for (int i=0;i<=N;i++){
		for (int k=1;k<=2;k++){
			long long n = L[k][i] + R[3-k][i+1];
			if (ans < n)
				ans = n;
		}
	}

	printf ("%lld\n",ans);

	return 0;
}
