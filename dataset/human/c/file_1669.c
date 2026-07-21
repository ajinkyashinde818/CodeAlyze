#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define rep(i,a,b) for(int (i) = (a) ; (i) < (b) ; (i) ++)
#define anin(a) printf("%d\n",a);
#define ando(a)printf("%lf\n",a);

int main(void){
	int N,ans(0);
	scanf("%d",&N);
	int A[N],B[N],C[N - 1];
	rep(i,0,N){
		scanf("%d",&A[i]);
	}
	rep(i,0,N){
		scanf("%d",&B[i]);
	}
	rep(i,0,N - 1){
		scanf("%d",&C[i]);
	}
	rep(i,0,N){
		ans += B[A[i] - 1];
		if(A[i] + 1 == A[i + 1] && i <= N -1){
			ans += C[A[i] - 1];
		}
	}
	anin(ans);
	return 0;
}
