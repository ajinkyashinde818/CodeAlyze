#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0,sum=0,n,p=1,i,j,a,b,q,k,l,m;
	scanf("%d %d",&n,&m);
	char s[100][100],s1[100][100];
	for(i=0;i<n;i++)
	scanf(" %s",s[i]);
	for(i=0;i<m;i++)
	scanf(" %s",s1[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(s[i][j]==s1[0][0])
			{
				
				if(n-i>=m && n-j>=m)
				{
					int f=0,c=0;
					//printf("%d %d\n",i,j);
					p=i,q=j;
					for(k=0,p=i;k<m;k++,p++)
					{
						
					
						for(l=0,q=j;l<m;l++,q++)
						{
							//printf("%d %d %d %d %d\n",c,p,q,k,l);
							if(s[p][q]!=s1[k][l])
							{
								f=1;
			
								break;
							}
							//q++;
							//c++;
						}
						//p++;
					}
					if(f==0)
					{
						printf("Yes");
						return 0;
					}
				}
			}
		}
	}
	printf("No");
}
