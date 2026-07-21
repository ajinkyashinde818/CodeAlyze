#include<stdio.h>
int N, K, A[200200];
int main(){
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
	}
	int l=0, r=1<<30;
	while(r-l > 1){
		int mid = (l+r)/2;
		int cnt = 0;
		for(int i=0; i<N; i++){
			cnt += (A[i]+mid-1)/mid-1;
		}
		if(cnt > K)l = mid;
		else r = mid;
	}
	printf("%d\n", r);
}
