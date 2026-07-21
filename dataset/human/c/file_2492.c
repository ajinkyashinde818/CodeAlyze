#include<stdio.h>

int main(void)
{
	int i,a=0,b=0,c=0;
	char s[4];
	scanf("%s",s);
	for(i=0;i<3;i++){
		if(s[i]=='a')
			a++;
		if(s[i]=='b')
			b++;
		if(s[i]=='c')
			c++;
	}
	if(a*b*c==0)
		printf("No");
	else
		printf("Yes");
	return 0;
}
