#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define rep(i,k,n) for(int (i)=(k);(i)<(n);(i)++)
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define abs(a) (a)>0 ?(a):-(a)
#define llong long long

int main(){
	llong N,K; scanf("%lld %lld",&N,&K);
	int a[N],flag[N];
	rep(i,0,N){
		int k; scanf("%d",&k);
		k--;
		a[i]=k;
		flag[i]=-1;	// 0から何回の移動でそこに行く？
	}
	int num=0;
	rep(i,0,K){
		if( flag[num]==-1 ){	// 未到達点
			flag[num] = i;
			num = a[num];
		}else{
			int k = i - flag[num];	// 周期
			K = (K-flag[num])%k + flag[num];
			num = 0;
			rep(j,0,K){
				num = a[num];
			}
			break;
		}
	}
	printf("%d",num+1);
	return 0;
}
