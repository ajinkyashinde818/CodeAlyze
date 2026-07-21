#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int i,j;
	int n;
	char a[9],b[9],c[9];
	int x,y;
	int r[4];
	
	scanf("%d ",&n);

	for(i=0;i<n;i++)
	{
		x = 0;
		y = 0;

		for(j=0;j<9;j++)
		{
			a[j] = 0;
			b[j] = 0;
			c[j] = 0;
		}

		scanf("%s %s ",a,b);
		
		for(j=0;j<8;j++)
		{
			if(a[j]=='m')
			{
				if(j != 0)
				{
					x += (a[j-1]-'0')*1000;
				}else{
					x += 1000;
				}
			}
			
			if(a[j]=='c')
			{
				if(j != 0 && a[j-1]-'0' <= 9)
				{
					x += (a[j-1]-'0')*100;
				}else{
					x += 100;
				}
			}
			
			if(a[j]=='x')
			{
				if(j != 0 && a[j-1]-'0' <= 9)
				{
					x += (a[j-1]-'0')*10;
				}else{
					x += 10;
				}
			}
			
			if(a[j]=='i')
			{
				if(j != 0 && a[j-1]-'0' <= 9)
				{
					x += (a[j-1]-'0');
				}else{
					x += 1;
				}
			}
		}
			
		for(j=0;j<8;j++)
		{
			if(b[j]=='m')
			{
				if(j != 0)
				{
					y += (b[j-1]-'0')*1000;
				}else{
					y += 1000;
				}
			}
			
			if(b[j]=='c')
			{
				if(j != 0 && b[j-1]-'0' <= 9)
				{
					y += (b[j-1]-'0')*100;
				}else{
					y += 100;
				}
			}
			
			if(b[j]=='x')
			{
				if(j != 0 && b[j-1]-'0' <= 9)
				{
					y += (b[j-1]-'0')*10;
				}else{
					y += 10;
				}
			}
			if(b[j]=='i')
			{
				if(j != 0 && b[j-1]-'0' <= 9)
				{
					y += (b[j-1]-'0');
				}else{
					y += 1;
				}
			}
		}
			
			r[0] = (x+y)/1000;
			if(r[0]>1)
			{
			  printf("%d",r[0]);
			}
			if(r[0]!=0)
			{
				printf("m");
			}
			
			r[1] = (x + y - r[0]*1000)/100;
			if(r[1]>1)
			{
				printf("%d",r[1]);
			}
			if(r[1]!=0)
			{
				printf("c");
			}
			
			r[2] = (x + y - r[0]*1000 -r[1] * 100) / 10;
			if(r[2]>1)
			{
				printf("%d",r[2]);
			}
			if(r[2]!=0)
			{
				printf("x");
			}
			
				r[3] = x + y - r[0]*1000 - r[1] *100 - r[2] *10;
			if(r[3]>1)
			{
				printf("%d",r[3]);
			}
			if(r[3]!=0)
			{
				printf("i");
			}
			
			printf("\n");
		}
	return 0;
}
