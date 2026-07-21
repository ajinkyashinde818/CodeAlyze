#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323
//void quick(int *,long long,long long);
char a[1000000];
int main(){
     
	int b[10000];
	int i,j,k;
	for(i=2;i<1000000;i++)
		a[i]=1;
	b[0]=0;
	k=1;
	i=2;
	while(i*i<1000000){
		b[k]=b[k-1]+i;
		j=i;
		while(i*j<1000000){
			a[i*j]=0;
			j++;
		}
		i++;
		while(a[i]==0)
			i++;
		k++;
	}
	while(i<1000000&&k<10005){
		b[k]=b[k-1]+i;
		i++;
		while(a[i]==0)
			i++;
		k++;
	}
	while(scanf("%d",&i)!=EOF)
		if(i!=0)
			printf("%d\n",b[i]);
		else
			break;
	return 0;
}
