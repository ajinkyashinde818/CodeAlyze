#include <stdio.h>
int main()
{
	char a,b,t,n;
	scanf("%c %c",&a,&b);
	if(a=='A')
		t=10;
		else if(a=='B')
		t=11;
		else if(a=='C')
		t=12;
		else if(a=='D')
		t=13;
		else if(a=='E')
		t=14;
		else if(a=='F')
		t=15;
	if(b=='A')
		n=10;
		else if(b=='B')
		n=11;
		else if(b=='C')
		n=12;
		else if(b=='D')
		n=13;
		else if(b=='E')
		n=14;
		else if(b=='F')
		n=15;
	if(t>n)
		printf(">\n");
		else if(t<n)
		printf("<\n");
		else if(t==n)
		printf("=\n");
	return 0;
}
