#include <stdio.h>
#include <ctype.h>

int mtoi(char x[]){
	int i,sum=0;

	for(i=0;x[i]!=0;i++){
		if(x[i] == 'm'){
			if(i && isdigit(x[i-1])) sum += (x[i-1] - '0') * 1000;
			else sum += 1000;
		}
		else if(x[i] == 'c'){
			if(i && isdigit(x[i-1])) sum += (x[i-1] - '0') * 100;
			else sum += 100;
		}
		else if(x[i] == 'x'){
			if(i && isdigit(x[i-1])) sum += (x[i-1] - '0') * 10;
			else sum += 10;
		}
		else if(x[i] == 'i'){
			if(i && isdigit(x[i-1])) sum += (x[i-1] - '0');
			else sum += 1;
		}
	}
	return sum;
}

void print_itom(int x){
	int i,d;

	if((d=x/1000) > 0){
		if(d != 1) printf("%d",d);
		printf("m");
	}
	x -= x/1000*1000;
	if((d=x/100) > 0){
		if(d != 1) printf("%d",d);
		printf("c");
	}
	x -= x/100*100;
	if((d=x/10) > 0){
		if(d != 1) printf("%d",d);
		printf("x");
	}
	x -= x/10*10;
	if(x > 0){
		if(x != 1) printf("%d",x);
		printf("i");
	}
	printf("\n");
}

int main(void){
	int n,sum;
	char a[12],b[12];

	scanf("%d",&n);
	while(n--){
		scanf("%s%s",a,b);
		sum = mtoi(a) + mtoi(b);
		print_itom(sum);
	}

	return 0;
}
