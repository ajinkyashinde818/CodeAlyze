#include <stdio.h>
#define MAX 25
#define NULL -1
typedef struct
{
	int p,l,r;
}Node;

Node T[MAX];
int n;

int getdepth(int i,int depth)
{
	if(T[i].p==NULL)//?????¶??? 
	{} 
	else
	{
		depth++;
		depth=getdepth(T[i].p,depth);
	}
	return depth;	
}

int getheight(int i)
{
	int h1=0,h2=0;
	if(T[i].l!=NULL)
	{
		h1++;
		h1=h1+getheight(T[i].l);
	}
	if(T[i].r!=NULL)
	{
		h2++;
		h2=h2+getheight(T[i].r);
	}
	return h1>h2?h1:h2;	
}

int getdegree(int i)
{
	if(T[i].l==NULL&&T[i].r==NULL)	
	return 0;
	else if(T[i].l!=NULL&&T[i].r!=NULL)
	return 2;
	else
	return 1;
}

int getsibling(int i)
{
	int p=T[i].p;
	if(p==NULL||T[p].l==NULL||T[p].r==NULL)
	return -1;
	if(T[p].l==i)
	return T[p].r;
	else
	return T[p].l;
}

void print(int i)
{
	printf("node %d: parent = %d, sibling = %d, degree = %d, ",i,T[i].p,getsibling(i),getdegree(i));
	printf("depth = %d, height = %d, ",getdepth(i,0),getheight(i));
	if(T[i].p==-1)
	printf("root\n");
	else if(T[i].l==-1&&T[i].r==-1)	
	printf("leaf\n");
	else
	printf("internal node\n");
}
int main(int argc, char *argv[])
{
	int i,node,left,right;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	T[i].p=NULL;
	for(i=0;i<n;i++)
	{
	scanf("%d%d%d",&node,&left,&right);
	T[node].l=left;
	T[node].r=right;
	if(left!=NULL)
	T[left].p=node;
	if(right!=NULL)
	T[right].p=node;
	}	
	for(i=0;i<n;i++)
	print(i);
	return 0;
}
