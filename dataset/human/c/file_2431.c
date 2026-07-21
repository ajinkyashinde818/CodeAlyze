#include<stdio.h>
int main(void)
{
	char s[4];
	scanf("%s",s);
	if(s[0]=='a' && s[1]=='b' && s[2]=='c'){
		printf("Yes\n");
	}
	else if(s[0]=='c' && s[1]=='a' && s[2]=='b'){
		printf("Yes\n");
	}
	else if(s[0]=='b' && s[1]=='c' && s[2]=='a'){
		printf("Yes\n");
	}
	else if(s[0]=='a' && s[1]=='c' && s[2]=='b'){
		printf("Yes\n");
	}
	else if(s[0]=='b' && s[1]=='a' && s[2]=='c'){
		printf("Yes\n");
	}
	else if(s[0]=='c' && s[1]=='b' && s[2]=='a'){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
