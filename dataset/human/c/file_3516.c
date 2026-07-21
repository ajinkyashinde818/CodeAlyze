#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
	long long N,K;
	int *A,*check;
	int i,p,loop,flag;
	char str[10000000],buf[10000000];
 
	fgets(str, sizeof(str), stdin);
	N=strtoll(strtok(str ," "),buf,10);
	K=strtoll(strtok(NULL," "),buf,10);

	A=(int*)calloc(N,sizeof(int));
	check=(int*)calloc(N,sizeof(int));

	fgets(str, sizeof(str), stdin);
	A[0]=atoi(strtok(str," "));
	for(i=1;i<N;i++){
		A[i]=atoi(strtok(NULL," "));
	}
	
	p=1;
	check[p-1]=1;flag=0;
	for(i=0;i<K;i++){
		p=A[p-1];
		if( (check[p-1]!=0) && (flag==0)){
          	loop=i+2-check[p-1];
			K=(K-(i+1))%loop+(i+1);
			flag=1;
		}else{
			check[p-1]=i+2;
		}
	}

	printf("%d\n",p);

	free(A);
	free(check);

	return 0;
}
