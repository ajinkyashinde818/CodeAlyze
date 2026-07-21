#include <stdio.h>
#include <string.h>
int min(int x, int y){return x<y?x:y;}
int main(void){
	int  a,b,k,i,l=0;
	scanf("%d %d %d",&a,&b,&k);
	i = min(a,b);
	while(1){
		if(a%i==0 && b%i==0){
			l++;		
			if(l==k)break;
		}
		i--;
	}
	printf("%d",i);
	return 0;
}
