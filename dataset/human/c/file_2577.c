#include<stdio.h>

int i; int num1=0; int num2=0; int num3=0;
int main(void){
	char str[100];
	scanf("%s",str);
	
	for(i=0;i<100;i++){
		if(str[i] == 'a'){
			num1++;}}
    for(i=0;i<100;i++){
		if(str[i] == 'b'){
			num2++;}}
	for(i=0;i<100;i++){
		if(str[i] == 'c'){
			num3++;}}
	if(num1==1&&num2==1&&num3==1){
		printf("Yes");}
	else{printf("No");}
	return 0;
}
