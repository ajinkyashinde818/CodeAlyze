#include <stdio.h>

int main(void)
{
	int d=0,m,i,N,A[200000],count=1,a[200000],place=0;
	long long K;
	scanf("%d",&N);
	scanf("%lld",&K);
	for(i=0;i<N;i++){
		a[i]=0;
		scanf("%d",&A[i]);
	}
	for(i=0;i<K;i++){
		m=place;
		place=A[m]-1;
		if(a[place]==0){
			a[place]=count;
		}else if(d==0){
			m=count-a[place];
			K=(long long)(K-i-1)%m+i+1;
			d++;
		}
		count++;
	}
	printf("%d",place+1);
	return 0;
}
