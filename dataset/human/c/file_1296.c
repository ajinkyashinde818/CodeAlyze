#include<stdio.h>

int func(int uma[],int c[])
{
	int num1=0,num2=0;
	int i;
	
	for(i=0;i<8;i++)
	{
		num1+=uma[i];
		num1*=10;
		num2+=c[i];
		num2*=10;
	}
	if(num1>num2)return 0;
	else if(num1<num2)return 1;
}

void logdata(int uma[],int num,int min)
{
	int i;
	printf("min:%d %d: ",min,num);
	for(i=0;i<8;i++)printf("%d ",uma[i]);
	printf("\n");
}

int main()
{
	int p[8]={0},c[8]={0};
	int uma[8]={4,1,4,1,2,1,2,1};
	int i,j,num=0,min=0,k,flag=0;
	
	while(scanf("%d %d %d %d %d %d %d %d",&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6],&p[7])!=EOF)
	{
		for(i=0;i<8;i++)
		{
			flag=0;
			num=0;
			for(j=0;j<8;j++)if(p[j]>uma[j])num+=(p[j]-uma[j]);
			
			if(i==0)
			{
				min=num;
				for(j=0;j<8;j++)c[j]=uma[j];
			}
			
			if(min>num)
			{
				min=num;
				for(j=0;j<8;j++)c[j]=uma[j];
			}
			else if(min==num)
			{
				flag=func(uma,c);
				if(flag==1)for(j=0;j<8;j++)c[j]=uma[j];
			}
			
			//logdata(uma,num,min);
			
			for(j=0;j<8;j++)
			{
				if(j==0)
				{
					k=uma[0];
					uma[0]=uma[1];
				}
				else if(j<7 && j>0)uma[j]=uma[j+1];
				else if(j==7)uma[j]=k;
			}
		}
		
		for(i=0;i<8;i++)
		{
			if(i!=7)printf("%d ",c[i]);
			else printf("%d",c[i]);
		}
		printf("\n");
	}
	return 0;
}
