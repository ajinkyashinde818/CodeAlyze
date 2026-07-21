#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ANS = 0;
	int N ;//
	int BSUM=0, CSUM=0,tmp;//
	int A[21];//各桁の数を格納
  	int B[21];//各桁の数を格納
  	int C[21];//各桁の数を格納
 
	//Nをスキャン
	scanf("%d", &N);
	//N個の数字をスキャン 0からN-1まで
 	for (int i = 0; i < N; i++) { 
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) { 
		scanf("%d", &B[i]);
      BSUM=BSUM+B[i];
	}
   	for (int i = 0; i < N-1; i++) { 
		scanf("%d", &C[i]);
	}
   	for (int i = 0; i < N-1; i++) { 
		if(A[i]==A[i+1]-1){
          tmp=A[i];
          CSUM=CSUM+C[tmp-1];
        }
	}
  
 
	ANS = BSUM + CSUM;
 
	printf("%d", ANS);
 
	return 0;
}
