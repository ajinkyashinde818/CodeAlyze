#include <stdio.h>

int main()
{
	char A[51][51],B[51][51];
	int i,j,k,l,n,m,c;
	bool flag=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%s",A[i]);
	for(i=0;i<m;i++) scanf("%s",B[i]);
	for(i=0;i<n-m+1 && flag==0;i++)
	{
		for(j=0;j<n-m+1 && flag==0;j++)
		{
			if(A[i][j]==B[0][0])
			{
				for(c=i;c<i+m;c++)
				{
					for(k=j,l=0;A[c][k]==B[c-i][l] && l<m;k++,l++) ;
					if(l!=m) break; 
				}
				if(c==i+m) flag=1;
			}
		}
	}
	printf("%s\n",flag ? "Yes" : "No");
}
