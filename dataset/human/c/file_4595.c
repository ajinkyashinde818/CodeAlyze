#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX 50
const int nil=-1;
struct node
{
	int parent;
	int left;
	int right;
};
struct node tree[MAX];
int depth[MAX];
int height[MAX];
int n;
void setdepth(int u,int p)
{
	if(u==nil)
		return;
	depth[u]=p;
	setdepth(tree[u].left,p+1);
	setdepth(tree[u].right,p+1);
	return;
}
int setheight(int u)
{
	int h1=0,h2=0;
	if(tree[u].left!=nil)
		h1=setheight(tree[u].left)+1;
	if(tree[u].right!=nil)
		h2=setheight(tree[u].right)+1;
	if(h1>h2)
		return height[u]=h1;
	return height[u]=h2;
}
int getsibling(int u)
{
	if(tree[u].parent==nil)
		return nil;
	if(tree[tree[u].parent].right!=u && tree[tree[u].parent].right!=nil)
		return tree[tree[u].parent].right;

	if(tree[tree[u].parent].left!=u && tree[tree[u].parent].left!=nil)
		return tree[tree[u].parent].left;
	return nil;
}
void input()
{
	int i,j,id,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		tree[i].parent=nil;
		tree[i].left=nil;
		tree[i].right=nil;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&id);
		for(j=1;j<=2;j++)
		{
			scanf("%d",&c);
			if(j==1)
				tree[id].left=c;
			else
				tree[id].right=c;
			tree[c].parent=id;
		}
	}
	return;
}
void output(int u)
{
	printf("node %d: ",u);
	printf("parent = %d, ",tree[u].parent);
	printf("sibling = %d, ",getsibling(u));
	int deg=0;
	if(tree[u].left!=nil)
		deg++;
	if(tree[u].right!=nil)
		deg++;
	printf("degree = %d, ",deg);
	printf("depth = %d, ",depth[u]);
	printf("height = %d, ",height[u]);
	if(tree[u].parent==nil)
		printf("root\n");
	else
		if(tree[u].left==nil && tree[u].right==nil)
			printf("leaf\n");
		else
			printf("internal node\n");
	
	return;
}
int main()
{
	input();
	int i,root;
	for(i=0;i<n;i++)
		if(tree[i].parent==nil)
			root=i;

	setdepth(root,0);
	setheight(root);
	for(i=0;i<n;i++)
		output(i);
	return 0;
}
