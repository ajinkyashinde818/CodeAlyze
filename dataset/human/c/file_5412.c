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
	int N,M,X; scanf("%d %d %d",&N,&M,&X);
	int C[N],A[N][M],flag[N],study[M];
	int min=200000000;
	rep(i,0,N){
		scanf("%d",&C[i]);
		rep(j,0,M){
			scanf("%d",&A[i][j]);
		}
	}
	int N_2=1;
	rep(i,0,N) N_2 *= 2;
	rep(i,0,N_2){
		int cost=0;
		int ii=i;
		rep(j,0,N){
			flag[j] = ii&1;
			ii /= 2;
		}
		rep(j,0,M) study[j]=0;
		rep(j,0,N){
			if( flag[j] ){
				cost += C[j];
				rep(k,0,M){
					study[k] += A[j][k];
				}
			}
		}
		if( cost > min ) continue;
		rep(j,0,M){
			if( study[j] < X ) break;
			if( j==M-1 ) min = cost;
		}
	}
	if( min==200000000 ) printf("-1");
	else printf("%d",min);
	return 0;
}
