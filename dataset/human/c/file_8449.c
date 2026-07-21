#include<stdio.h>
int main(void){
    int n,m;
    int A[100];
    int i,j,k,t;

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
	scanf("%d",&A[i]);
    }

    for(i=1;i<=m;i++){
        for(j=0;j<n-1;j++){
	    if(A[j]%i>A[j+1]%i)
		 t=A[j],A[j]=A[j+1],A[j+1]=t;	
	}
    }

    for(i=0;i<n;i++){
	printf("%d\n",A[i]);
    }

    return 0;
}
