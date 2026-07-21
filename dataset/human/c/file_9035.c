#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define rep(i,a,b) for(int (i) = (a) ; (i) < (b) ; (i) ++)
#define scin(a) scanf("%d",&a);
#define scdo(a) scanf("%lf",&a);
#define scch(a) scanf("%s",a);
#define anin(a) printf("%d\n",a);
#define ando(a) printf("%lf\n",a);
#define anch(a) printf("%s\n",a);

int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(void){
	int N,K,ans(0);
	scin(N)
	scin(K)
	int h[N];
	rep(i,0,N){
		scin(h[i])
		if(h[i] >=  K) ans++;
	}
	anin(ans)
	return 0;
}
