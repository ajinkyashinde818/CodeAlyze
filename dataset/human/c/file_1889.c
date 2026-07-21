#include <stdio.h>
#include <string.h>
#include <math.h>
#define lop(i, n) for(i=1; i<=n; i++)

int main()
{
	int N, i, cnt=0;
	int A[50], B[50], C[50];
	
	scanf("%d", &N);
	lop(i, N){
		scanf("%d", &A[i]);
	}
	lop(i, N){
		scanf("%d", &B[i]);
	}
	lop(i, N-1){
		scanf("%d", &C[i]);
	}
	
	A[0]=0; B[0]=0; C[0]=0;
	
	lop(i, N){
        cnt+=B[A[i]];
        if(B[A[i]]==B[A[i-1]+1]){
            cnt+=C[A[i-1]];
        }
    }
          
    printf("%d", cnt);
	return 0;
}
