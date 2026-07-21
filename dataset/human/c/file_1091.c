#include <stdio.h>

int main(){
	int i,j,x,y=0;
	char a[10],b[10];
	int a_i,b_i;
	scanf("%d",&x);
	while(y<x){
		a_i=0;
		b_i=0;
		scanf("%s %s",a,b);
		//printf("%s %s",a,b);
		j=0;
		while(a[j]){
			if(a[j]>'1'&&a[j]<='9'){
				switch(a[j+1]){
					case 'm':a_i+=(a[j]-'0')*1000;break;
					case 'c':a_i+=(a[j]-'0')*100 ;break;
					case 'x':a_i+=(a[j]-'0')*10  ;break;
					case 'i':a_i+=(a[j]-'0')*1   ;break;
					default:break;
				}
				j++;
			}else{
				switch(a[j]){
					case 'm':a_i+=1000;break;
					case 'c':a_i+=100 ;break;
					case 'x':a_i+=10  ;break;
					case 'i':a_i+=1   ;break;
					default:break;
				}
			}
			j++;
		}
		j=0;
		while(b[j]){
			if(b[j]>'1'&&b[j]<='9'){
				switch(b[j+1]){
					case 'm':b_i+=(b[j]-'0')*1000;break;
					case 'c':b_i+=(b[j]-'0')*100 ;break;
					case 'x':b_i+=(b[j]-'0')*10  ;break;
					case 'i':b_i+=(b[j]-'0')*1   ;break;
					default:break;
				}
				j++;
			}else{
				switch(b[j]){
					case 'm':b_i+=1000;break;
					case 'c':b_i+=100 ;break;
					case 'x':b_i+=10  ;break;
					case 'i':b_i+=1   ;break;
					default:break;
				}
			}
			j++;
		}
		//printf("\n%d %d\n",a_i,b_i);
		a_i+=b_i;
		b_i=a_i/1000;
		if(b_i>0){
			if(b_i>1){
				printf("%d",b_i);
			}
			printf("m");
		}
		b_i=a_i%1000/100;
		if(b_i>0){
			if(b_i>1){
				printf("%d",b_i);
			}
			printf("c");
		}
		b_i=a_i%100/10;
		if(b_i>0){
			if(b_i>1){
				printf("%d",b_i);
			}
			printf("x");
		}
		b_i=a_i%10;
		if(b_i>0){
			if(b_i>1){
				printf("%d",b_i);
			}
			printf("i");
		}
		printf("\n");
		
		
		y++;
	}
	return 0;
}
