#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
	int n,c;
	
	while(0<=scanf("%d",&n)){
		if(n==0)break;
		c=0;
		while(n!=1){
			if(n%2==0){
				n=n/2;
			}else{
				n=3*n+1;
			}
			++c;
		}
		printf("%d\n",c);
	}
	return 0;
}
