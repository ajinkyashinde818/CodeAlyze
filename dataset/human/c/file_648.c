#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef long long LL;
#define rep(i,n) for(LL i=0; i<(LL)(n); i++)

//qsort
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

//比較
int max(int a, int b){
	if (a>b) return a;
	else return b;
}

int min(int a,int b) {
	if(a>b) return b;
	else return a;
}

LL ans( LL n,LL xx){
	if(n == -1){
		return 0;
	}
	return (n/xx)+1;
}

//main関数
int main(){
	int M,N;
	scanf("%d %d",&N,&M);
	char A[N][N];
	char B[M][M];
	rep ( i , N ){
		scanf("%s",A[i]);
	}
	rep ( i , M ) {
		scanf("%s",B[i]);
	}
	
	rep( i , N-M+1 ){
		rep ( j , N-M+1){
			int flag = 0;
			rep( k , M ){
				rep( m , M ){
					 if( A[ i+k ][ j+m ] != B[k][m]) flag = 1;
				}
			}
			if(flag == 0){
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
