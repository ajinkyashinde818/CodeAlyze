#include <stdio.h>

int main(void) {
	char s[3];
	int i;
	int a,b,c;
	scanf("%s", s);
	
	a = b = c = 0;
	for (i=0; i<3; i++){
		if(s[i]=='a'){a=1;}
		else if(s[i]=='b'){b=1;}
		else if(s[i]=='c'){c=1;}
	}
	
	if(a==1 && b==1 && c==1)printf("Yes");
	else printf("No");
	
	
	
	return 0;
}
