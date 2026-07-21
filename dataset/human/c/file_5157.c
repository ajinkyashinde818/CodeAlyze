#include <stdio.h>
#define N 100001
#define none -1
typedef struct
{
	int parent;
  int leftch;
  int rightch;
}tree;

tree T[N];
int n;
int Depth(int ,int);
int Height(int);
int Degree(int);
int Sibling(int);
void Print(int);
int main()
{
	int i,node,left,right;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	T[i].parent=none;
	for(i=0;i<n;i++)
	{
	scanf("%d%d%d",&node,&left,&right);
	T[node].leftch=left;
	T[node].rightch=right;
	if(left!=none)
	T[left].parent=node;

	if(right!=none)
	T[right].parent=node;
	}	
	for(i=0;i<n;i++)
	Print(i);
	return 0;
}
int Depth(int A,int Dep)
{
	if(T[A].parent==none){ 
  }else{ 
		Dep++;
		Dep=Depth(T[A].parent,Dep);
	}
	return Dep;	
}

int Height(int A)
{
	int Hei1=0;
  int Hei2=0;
	if(T[A].leftch!=none)
	{
		Hei1++;
		Hei1=Hei1+Height(T[A].leftch);
	}
	if(T[A].rightch!=none)
	{
		Hei2++;
		Hei2=Hei2+Height(T[A].rightch);
	}
	return Hei1>Hei2?Hei1:Hei2;
}

int Degree(int A)
{
	if(T[A].leftch==none&&T[A].rightch==none)	
	return 0;
	else if(T[A].leftch!=none&&T[A].rightch!=none)
	return 2;
	else
	return 1;
}

int Sibling(int A)
{
	int B=T[A].parent;
	if(B==none||T[B].leftch==none||T[B].rightch==none)
	return -1;
	if(T[B].leftch==A)
	return T[B].rightch;
	else
	return T[B].leftch;
}

void Print(int A)
{
	printf("node %d: parent = %d, sibling = %d, degree = %d, ",A,T[A].parent,Sibling(A),Degree(A));
	printf("depth = %d, height = %d, ",Depth(A,0),Height(A));
	if(T[A].parent==-1)
	printf("root\n");
	else if(T[A].leftch==-1&&T[A].rightch==-1)	
	printf("leaf\n");
	else
	printf("internal node\n");
}
