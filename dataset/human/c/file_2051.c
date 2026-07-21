#include<stdio.h>
#include<numeric>
int a[10][10],o[10][10],f[10][10],N;
int dy[]={-1,-1,0,0,0,1,1},dx[]={-1,0,-1,0,1,0,1};
int C(int y,int x)
{
	if(y<0||x<0||y>=N||x>y)return 0;
	return 1;
}
int F(int y,int x,int s)
{
	if(!C(y,x))return 1;
	if(a[y][x]==0)return 0;
	if(a[y][x]!=s)return 1;
	if(f[y][x])return 1;
	f[y][x]=1;
	int r=1,i;
	for(i=0;i<7;++i)r=r&&F(y+dy[i],x+dx[i],s);
	return r;
}
int G(int y,int x,int s)
{
	if(!C(y,x))return 0;
	if(a[y][x]!=s)return 0;	
	a[y][x]=-1;	
	int r=1,i;
	for(i=0;i<7;++i)r+=G(y+dy[i],x+dx[i],s);
	return r;
}
int main()
{
	int S,i,j,k,l,m,r,s,t;
	while(scanf("%d%d",&N,&S),N)
	{
		for(i=0;i<N;++i)for(j=0;j<=i;++j)scanf("%d",&o[i][j]);
		r=-999;
		for(i=0;i<N;++i)for(j=0;j<=i;++j)
		{
			if(o[i][j]==0)
			{
				for(l=0;l<N;++l)for(m=0;m<=l;++m)a[l][m]=o[l][m];
				a[i][j]=S;
				for(s=k=0;k<7;++k)
				{
					for(l=0;l<N;++l)for(m=0;m<=l;++m)f[l][m]=0;
					l=i+dy[k],m=j+dx[k];
					if(C(l,m))
					{
						if(a[l][m]!=-1&&F(l,m,a[l][m]))	t=G(l,m,a[l][m]),s+=(i==l&&j==m || o[l][m]==S?-t:t);
					}
				}
				r=(r>s?r:s);
			}
		}
		printf("%d\n",r);
	}
	return 0;
}
