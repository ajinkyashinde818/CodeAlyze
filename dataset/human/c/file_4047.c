#include<stdio.h>

int main(){
	int a,b,k;
	scanf("%d%d%d", &a,&b,&k);
	int count=0, answer, i;
	if(a>b) i=b;
	else i=a;
	while(1){
		if((a%i == 0) && (b%i == 0)){
			answer = i;
			count++;
			if(count == k) break;
		}
		i--;
	}
	
	printf("%d", answer);
	
	return 0;
}
