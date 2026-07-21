#include<stdio.h>
int main()
{
	int n,m,i,j,k,l,f=1;
	char a[51][51],b[51][51];

	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
	for(i=0;i<m;i++)
		scanf("%s",b[i]);

	for(i=0;i<=n-m;i++)
		for(j=0;j<=n-m;j++){
			for(k=i;k<i+m;k++)
				for(l=j;l<j+m;l++)
					if(a[k][l]!=b[k-i][l-j])
						f=0;
			if(f){
				puts("Yes");
				return 0;
			}
			f=1;
		}
	puts("No");
	return 0;
}
