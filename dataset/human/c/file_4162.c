#include<stdio.h>
main()
{
	int a,b,c,flag,d = 1;
	int num[200],i,j,k;
	scanf("%d %d %d",&a,&b,&c);
	if(a > b)
	flag = b;
	else flag = a;
	for(i = flag; i > 0; i--)
	{
		if(a % i == 0&&b % i == 0)
		{
		 num[d] = i; 
		 d++;
	    }
	}
   printf("%d",num[c]);
}
