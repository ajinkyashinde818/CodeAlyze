#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(i,l,n) for(int (i)=(l);(i)<(n);(i)++)
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define abs(a) (a)>0?(a):-(a)
#define ll long long

int main(){
	int N,K,C; scanf("%d %d %d",&N,&K,&C);
	char S[N+2]; scanf("%s",S);
	int fast[K],last[K];
	int n=0;
	for(int i=0;i<K;){
		if( n >= N ) break;
		//printf("judge %d ",n);
		if( S[n]!='x' ){
			fast[i]=n;
			n += C+1;
			i++;
			//printf("Yes\n");
		}else{
			n++;
			//printf("No\n");
		}
	}
	n = N-1;
	for(int i=0;i<K;){
		if( n<0 ) break;
		if( S[n]!='x' ){
			last[K-1-i]=n;
			n -= C+1;
			i++;
		}else{
			n--;
		}
	}
	//rep(i,0,K) printf("%d %d\n",fast[i],last[i]);
	rep(i,0,K) if( fast[i]==last[i] ) printf("%d\n",fast[i]+1);
	return 0;
}
