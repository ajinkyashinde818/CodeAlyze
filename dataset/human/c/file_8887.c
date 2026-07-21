#include<stdio.h>
int main()
{
	char p[60][60];
	int a,b,i,j,k=0;
	scanf("%d %d",&a,&b);
	for(i=1;i<=a;i++)
	   scanf("%s",p[i]);
	if(a==1&&b==1)
	{
		if(p[1][0]=='#')
		printf("Yes");
		else printf("No");
	}
	else if(a==1)
	{
			for(j=0;j<b;j++)
		{
				if(j==0)
				{
					if(p[1][0]=='#'&&p[1][1]!='#')
					{
							k=1; break;
					}
				
				}
				else if(j==b-1)
				{
					if(p[1][b-1]=='#'&&p[1][b-2]!='#')
					{
							k=1; break;
					}
				
				}
				else {
				 
					if(p[1][j]=='#'&&p[1][j-1]!='#'&&p[1][j+1]!='#')
					{
							k=1; break;
					}
					
				    }}}
				    
	else if(b==1)
	{
			for(i=1;i<=a;i++)
		{
				if(i==1)
				{
					if(p[1][0]=='#'&&p[2][0]!='#')
					{
							k=1; break;
					}
				
				}
				else if(i==a)
				{
					if(p[a][0]=='#'&&p[a-1][0]!='#')
					{
							k=1; break;
					}
				
				}
				else {
				 
					if(p[i][0]=='#'&&p[i-1][0]!='#'&&p[i+1][0]!='#')
					{
							k=1; break;
					}
					
				    }			
	}}
	else
	{
		  
		  
	for(i=1;i<=a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(i==1)
			{
				if(j==0)
				{
					if(p[1][0]=='#'&&p[1][1]!='#'&&p[2][0]!='#')
					{
							k=1; break;
					}
				
				}
				else if(j==b-1)
				{
					if(p[1][b-1]=='#'&&p[1][b-2]!='#'&&p[2][b-1]!='#')
					{
							k=1; break;
					}
				
				}
				else {
				 
					if(p[1][j]=='#'&&p[1][j-1]!='#'&&p[1][j+1]!='#'&&p[2][j]!='#')
					{
							k=1; break;
					}
					
				    }
				
		
		}
		else if(i==a)
		{
			if(j==0)
				{
					if(p[a][0]=='#'&&p[a][1]!='#'&&p[a-1][0]!='#')
					{
							k=1; break;
					}
				
				}
				else if(j==b-1)
				{
					if(p[a][b-1]=='#'&&p[a][b-2]!='#'&&p[a-1][b-1]!='#')
					{
							k=1; break;
					}
				
				}
				else {
				 
					if(p[a][j]=='#'&&p[a][j-1]!='#'&&p[a][j+1]!='#'&&p[a-1][j]!='#')
					{
							k=1; break;
					}
					
				    }
		}
		else{
			if(j==0)
				{
					if(p[i][0]=='#'&&p[i][1]!='#'&&p[i-1][0]!='#'&&p[i+1][0]!='#')
					{
							k=1; break;
					}
				
				}
				else if(j==b-1)
				{
					if(p[i][b-1]=='#'&&p[i][b-2]!='#'&&p[i-1][b-1]!='#'&&p[i+1][b])
					{
							k=1; break;
					}
				
				}
				else {
				 
					if(p[i][j]=='#'&&p[i][j-1]!='#'&&p[i][j+1]!='#'&&p[i-1][j]!='#'&&p[i+1][j]!='#')
					{
							k=1; break;
					}
					
				    }
		}
	}	if(k==1)break;
}
	
	

	}
	if(k==1)
	printf("No");
	else printf("Yes");
	return 0;
 }
