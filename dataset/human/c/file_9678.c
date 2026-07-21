#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 100010
struct node
{
	int parent;
	int left;
	int right;
};
const int nil=-1;
struct node tree[MAX];
int depth[MAX];
int n;
void setdepth(int u,int p)
{
	depth[u]=p;
	if(tree[u].right!=nil)
		setdepth(tree[u].right,p);
	if(tree[u].left!=nil)
		setdepth(tree[u].left,p+1);
}
void input()
{
	int i,j,id,k,c,lastc;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		tree[i].parent=nil;
		tree[i].left=nil;
		tree[i].right=nil;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&id,&k);
		for(j=1;j<=k;j++)
		{
			scanf("%d",&c);
			if(j==1)
				tree[id].left=c;
			else
				tree[lastc].right=c;
			lastc=c;
			tree[c].parent=id;
		}
	}
	return;
}
void output(int u)
{
	int i,c;
	printf("node %d: ",u);
	printf("parent = %d, ",tree[u].parent);
	printf("depth = %d, ",depth[u]);
	if(tree[u].parent==nil)
		printf("root, ");
	else
		if(tree[u].left==nil)
			printf("leaf, ");
		else
			printf("internal node, ");
	printf("[");
	for(i=1,c=tree[u].left;c!=nil;i++,c=tree[c].right)
	{
		if(i>1)
			printf(", ");
		printf("%d",c);
	}
	printf("]\n");
	return;
}
int main()
{
	int i,r;
	input();
	for(i=0;i<n;i++)
		if(tree[i].parent==nil)
			r=i;
	setdepth(r,0);
	for(i=0;i<=n-1;i++)
		output(i);
	return 0;
}
