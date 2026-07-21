#include <stdio.h>
#include <string.h>
#define N 100

int naosi(char []);
void kyosei(int);

int main(void){
	int i,j;
	int n,a,b;
	char str[N];
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		a=naosi(str);
		scanf("%s",str);
		b=naosi(str);
		a+=b;
		kyosei(a);
	}
	return 0;
}

int naosi(char str[]){
		int k=0;
		int i,j;
		int kotae=0;
		for(i=0;i<strlen(str);i++){
			if('0'<=str[i] && str[i]<='9'){
				k*=10;
				k+=str[i]-'0';
			}else{
				switch(str[i]){
					case 'm':
					if(k==0) kotae+=1000;
					else kotae+=k*1000;
					k=0;
					break;
					case 'c':
					if(k==0) kotae+=100;
					else kotae+=k*100;
					k=0;
					break;
					case 'x':
					if(k==0) kotae+=10;
					else kotae+=k*10;
					k=0;
					break;
					case 'i':
					if(k==0) kotae+=1;
					else kotae+=k*1;
					k=0;
					break;
				}
			}
		}
		return kotae;
}

void kyosei(int a){
	int i,j;
	if(a/1000!=0){
		if(a/1000==1){
			printf("m");
		}else{
			printf("%dm",a/1000);
		}
	}
	a%=1000;
	
	if(a/100!=0){
		if(a/100==1){
			printf("c");
		}else{
			printf("%dc",a/100);
		}
	}
	a%=100;
	
	if(a/10!=0){
		if(a/10==1){
			printf("x");
		}else{
			printf("%dx",a/10);
		}
	}
	a%=10;
	
	if(a/1!=0){
		if(a/1==1){
			printf("i");
		}else{
			printf("%di",a/1);
		}
	}
	a%=1;
	printf("\n");
}
