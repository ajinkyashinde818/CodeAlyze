#include<stdio.h>
int main()
{
	char x,y;
	int xa,ya;
	scanf("%c\n",&x);
	scanf("%c\n",&y);
	
	switch (x)
	{
		case 'A':
		xa=10;
		break;
		
		case 'B':
		xa=11;
		break;
		
		case 'C':
		xa=12;
		break;
		
		case 'D':
		xa=13 ;
		break;
		
		case 'E':
		xa=14;
		break;
		
		case 'F':
		xa=15;
		break;
		
		default :
		break;
	}
	
	switch (y)
	{
		case 'A':
		ya=10;
		break;
		
		case 'B':
		ya=11;
		break;
		
		case 'C':
		ya=12;
		break;
		
		case 'D':
		ya=13 ;
		break;
		
		case 'E':
		ya=14;
		break;
		
		case 'F':
		ya=15;
		break;
		
		default :
		break;
	}	
	
	if(xa==ya){printf("=");}
	if(xa>ya){printf(">");}
	if(xa<ya){printf("<");}	

	return 0;
}
