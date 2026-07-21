#include <stdio.h>
#include <stdlib.h>


int N;
long int a[300000];

int cmpnum(const void *n1,const void *n2){
    if(*(long int *)n1<*(long int *)n2)
	return 1;
    else if(*(long int *)n1>*(long int *)n2)
	return -1;
    else 
	return 0;
}

int main()
{
    long int sum=0;
    scanf("%d",&N);
    for (int i=0;i<3*N;i++)
	scanf("%ld",&a[i]);
    qsort(a,3*N,sizeof(long int),cmpnum);
    for(int i=0;i<2*N;i++){
	if(i%2==1)
	    sum+=a[i];
    }
    printf("%ld\n",sum);
    return 0;
}
