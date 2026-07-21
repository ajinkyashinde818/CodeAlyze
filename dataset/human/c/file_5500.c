#include <stdio.h>
#include <math.h>
#define N_MAX 104729 /*10000ÔÚÌf*/

int main(void){
	char a[N_MAX+1]; int i, j, sum;
	
	/* eratosthenes */
	a[0]=0, a[1]=0;
	for(i=2; i<=N_MAX; i++) a[i]=1;
	
	for(i=2; i<=(int)sqrt(N_MAX); i++)
		if(a[i])
			for(j=2*i; j<=N_MAX; j+=i) a[j]=0;
	
	while(~scanf("%d",&i), i!=0){
		j=0, sum=0;
		
		while(i>0){
			while(a[j]==0) j++;
			sum+=j, i--;
			
			j++;
		}
		
		printf("%d\n",sum);
	}
	
	return 0;
}
