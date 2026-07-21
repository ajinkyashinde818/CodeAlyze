#include <stdio.h>
#include <math.h>
int main()
{   
int K,N,i;
int worse=0;
scanf("%d %d",&K,&N);
int A[N];
int B[N];
for(i=0;i<N;i++){
scanf("%d",&A[i]);
    B[i]=A[i]-A[i-1];
    if(B[i]>worse){
    	worse=B[i];
    }
    }
    int z = K-A[N-1]+A[0];
    if(z>worse){
    	worse=z;
    }
printf("%d", K-worse);
    return 0;
}
