#include <stdio.h>
int main(void){
	char s[3];
	scanf("%s",&s);
	int flag = 0;
	int i;
	for(i=0;i<3;i++){
		if(s[i] =='a'){
			flag +=2;
		}
		if(s[i] =='b'){
			flag +=3;
		}
		if(s[i] =='c'){
			flag +=5;
		}
	}
	if(flag==10){
		printf("Yes");
		return 0;
	}else{
		printf("No");
		return 0;
	}
	return 0;
}
