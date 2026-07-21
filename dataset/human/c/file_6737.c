#include<stdio.h>
#include<stdlib.h>
int n,m,i,f[10000][2],a;

int cmp(const void *a,const void *b)
{
	return ((int*)a)[0]-((int*)b)[0];
}

int main()
{
	for(;scanf("%d%d",&n,&m),n;)
	{
		int r[501]={0},x[501]={0};
		for(i=0;i<m;i++)
			scanf("%d%d",&f[i][0],&f[i][1]);
		qsort(f,m,sizeof(int[2]),cmp);

		for(i=a=0;f[i][0]==1;i++)
			r[f[i][1]]=1,x[f[i][1]]=1;
		for(;i<m;i++)
		{
			if(r[f[i][0]]&&!x[f[i][1]])
				x[f[i][1]]=1;
			else if(r[f[i][1]]&&!x[f[i][0]])
				x[f[i][0]]=1;
		}
		for(i=a=0;i<=n;i++)
			if(x[i])
				a++;
		printf("%d\n",a);
	}

	return 0;
}
