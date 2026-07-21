#include<stdio.h>
#include<math.h>
int prime(int n);

int main(void){
	int i,n,p[10010],s;
	i=0;n=2;
	while(i<10000){
		if(prime(n)==0){p[i++]=n;}
		n++;
	}
	while(1){
		scanf("%d",&n);
		if(n==0){break;}
		s=0;
		for(i=0;i<n;i++){
			s+=p[i];
		}
		printf("%d\n",s);
	}
	return 0;
}
int prime(int n){
	int i;
	if(n==2){return 0;}
	if(n%2==0){return 1;}
	for(i=3;i<sqrt(n)+1;i+=2){
		if(n%i == 0){return 1;}
	}
	return 0;
}
