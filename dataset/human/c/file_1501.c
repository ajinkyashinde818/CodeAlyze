#include <stdio.h>

int main(void)
{
	char x,y,A,B,C,D,E,F;
	char s[]={A,B,C,D,E,F};
	
	scanf("%c %c",&x,&y);
	
	for(int i=0;i<6;i++){
		s[i]=i;
	}
	
	if(x>y){
		printf(">\n");
	}else if(x==y){
		printf("=\n");
	}else{
		printf("<\n");
	}
		
	
	return 0;
}
