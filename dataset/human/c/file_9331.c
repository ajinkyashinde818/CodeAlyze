#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
    int N,K,i,S;
    S=0;
    unsigned int *h;
    scanf("%d",&N);
    scanf("%d",&K);
    h=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
	scanf ("%d",&h[i]);
    	}
    for(i=0;i<N;i++){
	if(h[i]>=K){
		S++;
	}
    }
    printf("%d\n",S);
    return 0;
}
