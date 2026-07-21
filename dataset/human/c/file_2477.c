#include <stdio.h>

int main(void)
{
	char s[100];
	int a=0;
	int b=0;
	
	scanf("%s",s);
	
	for(int i=0;i<3;i++){
		if(s[i]=='a'){
			a++;
		}
		if(s[i]=='b'){
			b++;
		}
	}
	
	if(a==1&&b==1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}
