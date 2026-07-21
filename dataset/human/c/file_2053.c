#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define rep(i,x) for(i=0;i<x;i++)
#define rrep(i,x) for(i=x-1;i>=0;i--)
#define rep_to(a,i,x) for(i=a;i<x;i++)
#define si_1(x) scanf("%d",&x)
#define si_2(x,y) scanf("%d %d",&x,&y)
#define debug(x) printf("x:%d\n",x)

int main()
{
	int i=0,j=0,n,m;
	int mark,num[114]={};
	int min=0,max=0,len=0;
	int flag=0;

	while(si_2(m,n)!=EOF)
	{
		i=0;
		j=0;
		min=0;
		max=0;
		len=0;
		flag=0;

		if(n==0 && m==0)break;
		rep(i,n)
		{
			si_1(num[i]);
			max+=num[i];
		}
		while(min<=max)
		{
			mark=(min+max)/2;
			flag=0;
			i=0;
			j=0;
			while(1)
			{
				++i;
				len=0;
				for(;j<n;j++)
				{
					if(mark<=len+num[j])
					{
						break;
					}
					else len+=num[j];
				}
				if(i<=m && j==n)//?¶?????????¬?????\??£??????
				{				
					flag=1;
					break;
				}
				else if(i>m)//??\?????????????????£??????
				{
					flag=0;
					break;
				}
			}
			if(flag==0)min=mark+1;
			else if(flag==1)max=mark-1;
		}
		printf("%d\n",(min+max)/2);
	}
	return 0;
}
