#include<stdio.h>
#include<string.h>

int main()
{
	char ch,s[300009],f[200009],r[200009];
	gets(s);
	int len=strlen(s);
	int front=0,rear=0,q,i,t,order,now=1;
	scanf("%d",&q);
	
	for (i=1;i<=q;i++)
	{
		scanf("%d",&t);
		if (t==1) now=1-now;
		else
		{
			scanf("%d",&order);
			if (order==1)
			{
				if (now==1)
				{
					++front;
					ch=getchar();
					f[front]=getchar();
				}
				else 
				{
					++rear;
					ch=getchar();
					r[rear]=getchar();
				}
			}
			else 
			{
				if (now==0)
				{
					++front;
					ch=getchar();
					f[front]=getchar();
				}
				else 
				{
					++rear;
					ch=getchar();
					r[rear]=getchar();
				}
			}
		}
	}
	
	if (now==1)
	{
		for (i=front;i>=1;i--)
			putchar(f[i]);
		for (i=0;i<len;i++)
			putchar(s[i]);
		for (i=1;i<=rear;i++)
			putchar(r[i]);
	}
	else
	{
		for (i=rear;i>=1;i--)
			putchar(r[i]);
		for (i=len-1;i>=0;i--)
			putchar(s[i]);
		for (i=1;i<=front;i++)
			putchar(f[i]);
	}
	
	return 0;
}
