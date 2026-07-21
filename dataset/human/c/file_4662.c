#include<stdio.h>
#include<string.h>

typedef struct D
{
	int n,r,l,d,p,dep,h,sub,deg;
}D;

D node[30];
int i,j,N,r,l,n;

int dfs(int p,int d)
{
	int a,b;
	if(p==-1)return -1;
	node[p].dep=d;
	a=dfs(node[p].r,d+1);
	b=dfs(node[p].l,d+1);
	if(a==-1&&b==-1)
		node[p].h=0;
	else
		node[p].h=(a>b?a:b)+1;
	return node[p].h;
}

int main()
{
	memset(node,-1,sizeof(node));
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d%d%d",&n,&l,&r);
		node[n].l=l;
		node[n].r=r;
		node[n].deg=(r!=-1)+(l!=-1);
		node[l].sub=r;
		node[r].sub=l;
		if(l!=-1)node[l].p=n;
		if(r!=-1)node[r].p=n;
	}
	for(i=0;i<N;i++)
		if(node[i].p==-1)
			dfs(i,0);

	for(i=0;i<N;i++)
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
		i,node[i].p,node[i].sub,node[i].deg,node[i].dep,node[i].h,node[i].p==-1?"root":node[i].l==-1&&node[i].r==-1?"leaf":"internal node");
	return 0;
}
