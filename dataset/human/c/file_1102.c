#include <stdio.h>
#include <ctype.h>

int parse(char* str){
	int i,sum=0;
	int d=1;
	for(i=0;str[i];i++){
		if(isdigit(str[i])){
			d=str[i]-'0';
		}else{
			switch(str[i]){
				case 'm':
					sum+=1000*d;
					break;
				case 'c':
					sum+=100*d;
					break;
				case 'x':
					sum+=10*d;
					break;
				case 'i':
					sum+=d;
					break;
				default:
					;
			}
			d=1;
		}
	}
	return sum;
}

void print(int i){
	if(i/1000){
		if((i/1000)==1){
			printf("m");
		}else{
			printf("%dm",i/1000);
		}
	}
	i%=1000;
	if(i/100){
		if((i/100)==1){
			printf("c");
		}else{
			printf("%dc",i/100);
		}
	}
	i%=100;
	if(i/10){
		if((i/10)==1){
			printf("x");
		}else{
			printf("%dx",i/10);
		}
	}
	i%=10;
	if(i){
		if(i==1){
			printf("i");
		}else{
			printf("%di",i);
		}
	}
	printf("\n");
}

void solve(){
	char A[10];
	char B[10];
	scanf("%s %s", A, B);
	int sum=parse(A)+parse(B);
	print(sum);
}

int main(void){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		solve();
	}
	return 0;
}
