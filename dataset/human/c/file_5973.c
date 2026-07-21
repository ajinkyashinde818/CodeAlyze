#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int 
main(){
	long int x[200000],max,min;
	max=-pow(10,9);//min[0]=-pow(10,9);
	long int i,n;
	scanf("%ld",&n);
	for(i=0;i<n;i++){
		scanf("%ld",&x[i]);
	}
	for(i=0;i<n;i++){
		if(i==0)min=x[i];
		else{
			
			if(max<x[i]-min)max=x[i]-min;
			if(min>x[i])min=x[i];
		}
		//printf("%d<min%ld>\n",i,MM);//min[i]);
	}
	

	printf("%ld\n",max);
 return 0;
}
