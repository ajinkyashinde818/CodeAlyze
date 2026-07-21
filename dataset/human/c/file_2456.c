#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
	int a=0,b=0,c=0,i;
	char s[4];
	scanf("%s",s);
	for(i=0;i<3;i++){
		if(s[i]=='a') a=1;
		if(s[i]=='b') b=1;
		if(s[i]=='c') c=1;
	}
	if(a&&b&&c){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
