#include<stdio.h>

typedef long long int int64;

char ffc;
int fff;
int nextInt();

int N, K, i, j, k, l, c;
int64 answer, sum;
int a[1000];
int64 b[500500];

int main(void){
	N = nextInt();
	K = nextInt();
	for(i=0; i<N; i++){
		a[i] = nextInt();
	}
	l = N*(N+1)/2;
	k = 0;
	for(i=0; i<N; i++){
		sum=0;
		for(j=i; j<N; j++){
			sum+=a[j];
			b[k++]=sum;
		}
	}
	answer = 0;
	for(k=39; k>=0; k--){
		c=0;
		for(i=0; i<l; i++){
			if((b[i]>>k)&1){c++;}
		}
		if(c>=K){
			answer+=((int64)1)<<k;
			j=0;
			for(i=0; i<l; i++){
				if((b[i]>>k)&1){b[j++]=b[i];}
			}
			l=j;
		}
	}
	printf("%lld\n", answer);
	return 0;
}

int nextInt(){
	fff=0;
	ffc = getchar();
	while((ffc<'0')||('9'<ffc)){
		ffc=getchar();
	}
	while((ffc>='0')&&(ffc<='9')){
		fff=fff*10+(ffc-'0');
		ffc=getchar();
	}
	return fff;
}
